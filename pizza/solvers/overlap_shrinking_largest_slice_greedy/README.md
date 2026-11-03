> **Largest slice, shrinking the slices it overlaps**
>
> Source: https://github.com/sagishporer/hashcode-practice-pizza
>
> Method overview:
> 1. Scans for an unsliced cell and finds the largest valid slice that grows from it in all directions.
> 2. The slice may overlap existing slices as long as what remains of them stays valid, and those slices are shrunk.
> 3. Rescans the slices and retries growing them.
>
> Our runs: sum of means 959,187 ([scores](../../output/overlap_shrinking_largest_slice_greedy/scores.md)).

# Hash Code 2017, 2018 & 2019 practice problem solution: Pizza

[Problem definition & data files](https://bytefreaks.net/google/practice-problem-for-google-hash-code-2018)

Algorithm type: greedy. 
1. Scan the pizza for unsliced position.
2. Find largest valid slice using this position. Grow from current position in all directions. Allow overslapping with existing slices, as long as the remaining part of the slice is valid after overlap.
3. If valid slice found - clear all the ingredients contained in the slice & add slice. Update all overlapped slices.
4. If scan not completed - go to 1.
5. Rescan slices, retry growing the slices.

Solution score: 959,202 
- Example: 15
- Small: 42
- Medium: 49,576
- Big: 909,569

Please ignore code style. The objective was to complete the task as fast as possible.
