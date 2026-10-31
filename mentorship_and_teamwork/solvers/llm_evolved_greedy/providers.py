"""Provider adapters for MicroEvolve.

The evolution loop in ``evolve.py`` is provider-agnostic: it builds a single
system prompt and a running conversation of plain-text turns, and after each
model reply it only needs the assistant text and the token usage. This module
hides the three vendor SDKs behind one neutral interface so the loop never
imports a vendor SDK directly.

Neutral message history shared by all adapters::

    messages = [{'role': 'user' | 'assistant', 'content': <str>}, ...]

Each adapter's ``complete`` returns a :class:`Result` with the assistant text
and a normalized usage dict (``input``, ``output``, ``cache_read``,
``cache_write`` token counts).

``effort`` is a neutral reasoning level: ``'auto' | 'low' | 'medium' | 'high'``.
Each adapter maps it onto its provider's own reasoning control.
"""

from dataclasses import dataclass

# Neutral effort -> explicit thinking-token budgets, used by the providers whose
# reasoning control is a token budget rather than a named level. 'auto' is
# handled specially per provider (adaptive / dynamic).
_BUDGETS = {'low': 4000, 'medium': 8000, 'high': 16000}


@dataclass
class Result:
    """Normalized model response: assistant text plus token usage."""
    text: str
    usage: dict  # keys: input, output, cache_read, cache_write


class AnthropicProvider:
    """Claude via the Anthropic Messages API (keeps ephemeral prompt caching)."""

    def __init__(self):
        import anthropic
        # The SDK retries transient errors (429/5xx incl. 529) with backoff;
        # raise the budget so brief overloads don't surface as exceptions.
        self.client = anthropic.Anthropic(max_retries=6)

    def complete(self, model, system, messages, max_tokens, effort):
        if effort == 'auto':
            thinking = {'type': 'adaptive'}
        else:
            thinking = {'type': 'enabled', 'budget_tokens': _BUDGETS[effort]}
        response = self.client.messages.create(
            model=model,
            max_tokens=max_tokens,
            thinking=thinking,
            system=[{
                'type': 'text',
                'text': system,
                'cache_control': {'type': 'ephemeral'},
            }],
            messages=messages,
        )
        text = ''.join(b.text for b in response.content if b.type == 'text')
        u = response.usage
        usage = {
            'input': u.input_tokens,
            'output': u.output_tokens,
            'cache_read': u.cache_read_input_tokens or 0,
            'cache_write': u.cache_creation_input_tokens or 0,
        }
        return Result(text=text, usage=usage)


class OpenAIProvider:
    """OpenAI reasoning models via the Chat Completions API.

    Caching is automatic server-side; cached prompt tokens are reported back and
    folded into ``cache_read``. Requires a reasoning model (GPT-5 / o-series) so
    that ``reasoning_effort`` is accepted.
    """

    def __init__(self):
        import openai
        self.client = openai.OpenAI(max_retries=6)

    def complete(self, model, system, messages, max_tokens, effort):
        chat = [{'role': 'developer', 'content': system}] + messages
        response = self.client.chat.completions.create(
            model=model,
            messages=chat,
            max_completion_tokens=max_tokens,
            reasoning_effort='medium' if effort == 'auto' else effort,
        )
        text = response.choices[0].message.content or ''
        u = response.usage
        details = getattr(u, 'prompt_tokens_details', None)
        cached = getattr(details, 'cached_tokens', 0) or 0
        usage = {
            'input': u.prompt_tokens - cached,
            'output': u.completion_tokens,
            'cache_read': cached,
            'cache_write': 0,
        }
        return Result(text=text, usage=usage)


class GoogleProvider:
    """Gemini via the google-genai SDK.

    Implicit context caching is automatic on 2.5 models; cached tokens are
    reported back and folded into ``cache_read``.
    """

    def __init__(self):
        from google import genai
        from google.genai import types
        self.genai = genai
        self.types = types
        # google-genai's retry knobs are version-dependent; transient errors are
        # covered by the application-level retry loop in evolve.py instead.
        self.client = genai.Client()

    def complete(self, model, system, messages, max_tokens, effort):
        types = self.types
        contents = [
            types.Content(
                role='model' if m['role'] == 'assistant' else 'user',
                parts=[types.Part(text=m['content'])],
            )
            for m in messages
        ]
        budget = -1 if effort == 'auto' else _BUDGETS[effort]
        config = types.GenerateContentConfig(
            system_instruction=system,
            max_output_tokens=max_tokens,
            thinking_config=types.ThinkingConfig(thinking_budget=budget),
        )
        response = self.client.models.generate_content(
            model=model, contents=contents, config=config,
        )
        text = response.text or ''
        m = response.usage_metadata
        cached = m.cached_content_token_count or 0
        prompt = m.prompt_token_count or 0
        thoughts = getattr(m, 'thoughts_token_count', 0) or 0
        usage = {
            'input': prompt - cached,
            'output': (m.candidates_token_count or 0) + thoughts,
            'cache_read': cached,
            'cache_write': 0,
        }
        return Result(text=text, usage=usage)


_PROVIDERS = {
    'anthropic': AnthropicProvider,
    'openai': OpenAIProvider,
    'google': GoogleProvider,
}


def get(name):
    """Construct the provider adapter for ``name`` (anthropic|openai|google)."""
    try:
        return _PROVIDERS[name]()
    except KeyError:
        raise ValueError(
            f'unknown provider {name!r}; choose from {sorted(_PROVIDERS)}'
        )
