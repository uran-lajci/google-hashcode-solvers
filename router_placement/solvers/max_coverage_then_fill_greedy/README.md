> **Greedy at full coverage, then filling the blanks**
>
> Source: https://github.com/SimylinK/Google-HashCode-2017
>
> Method overview:
> 1. Places every router that can reach its maximum coverage area.
> 2. Links those routers, each to the closest connected point.
> 3. Fills the remaining gaps with more routers while the budget lasts.
>
> Our runs: sum of means 537,507,292 ([scores](../../output/max_coverage_then_fill_greedy/scores.md)).

Projet Poly#
============

_Le projet est repris du concours Google Hash Code 2017,
un concours de programmation par équipe_

**Objectif**

Étant donné un plan de construction, décidez où placer les routeurs
sans fil et comment les connecter au réseau fédérateur pour maximiser
la couverture et minimiser les coûts


L'équipe
===========

GOMEZ Tristan

LI Pengyu

MONVOISIN Mathilde

PAGANO Lucas

MARAVAL Nathan

Utilisation
===========
Se placer dans le dossier bin, puis :

Pour la résolution du problème : ./googleHashCode2017.exe <cheminFichierInput>
Exemple : ./googleHashCode2017.exe "../inputAndOutput/charleston_road.in"

Pour l'arbitre et le calcul de performances : ./googleHashCode2017_Arbitre.exe <cheminDossierExecutables> <cheminFichierOutput>
Exemple : ./googleHashCode2017_Arbitre.exe "../runExe" "../inputAndOutput/charleston_road.out"
