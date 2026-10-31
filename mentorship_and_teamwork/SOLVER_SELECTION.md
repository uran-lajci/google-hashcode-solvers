# Mentorship and Teamwork: choosing the best solvers

Google Hash Code 2022, Qualification round. 196 repositories, and 2 were kept. This selection was cut short: only the kept repositories got 10-minute runs, so the removed programs are compared by a single 5-minute run, and 90 repositories have no score from us at all.

## Kept

| Solver | B | C | D | E | F | Sum | % of top team |
|---|---:|---:|---:|---:|---:|---:|---:|
| [llm_evolved_greedy](solvers/llm_evolved_greedy/) (`MicroEvolve`) | **1,057,446** | **285,714** | **2,853,365** | **1,656,494** | **1,381,929** | 7,234,948 | 171.4% |
| [instance_specific_greedy](solvers/instance_specific_greedy/) (`mentorship-teamwork`) | 1,032,469 | 273,810 | 2,608,736 | 1,648,976 | 899,143 | 6,463,134 | 153.1% |

Both solvers are one program per instance, so these rows take each instance's best program. All the programs are deterministic, so the best is also the mean.

- **`llm_evolved_greedy`** is first on all five instances.
- **`instance_specific_greedy`** is first on none, and is kept by the 5% rule, which needs at least 4,009,224 (95% of the top team's 4,220,236). Its `d.cpp` alone totals 5,758,397, so this does not depend on picking a program per instance. `llm_evolved_greedy`'s `d.cpp` alone totals 5,768,242.
- It replaces `HashCode2022_Nanored4498`, the repository it was refactored from. The refactor adds a time limit and fixes the capacity and parsing errors that crash the original on some instances.

## What we did

1. **Collected.** 195 repositories were already in the folder. `mentorship-teamwork` was added at this selection.
2. **Screened.** Instances B–F, 1 run per instance with seed 1 and a 5-minute limit, at most 6 at a time, each pinned to its own physical core, scored with the official judge in `google-hashcode-judge/mentorship_and_teamwork/judge.py`. A rejected output counts as 0. This covers 160 programs from 104 repositories, 800 runs. Programs with a fixed input path were given the real instance at that path.
3. **Kept repositories at the 10-minute limit.** All 10 programs of the two kept repositories, 88 runs. Outputs that finished inside the limit were repeated and were byte-identical. `e.cpp` on E and `f.cpp` on F of `MicroEvolve` did not finish with six programs running at once, so they were run again with only two programs on the machine, with a 30-minute limit. They took 448 s and 574 s, which is inside 10 minutes, and are the scores above.
4. **Selected.** A solver is kept if it is first on an instance, by its best result over all runs, or if the sum of its per-instance means is within 5% of the best total in the competition.

## What was not run

The full protocol was stopped because of its run time, by decision of the collection's owner. So:

- **No 10-minute runs for the removed programs.** 155 runs from 64 programs gave no valid output at 5 minutes and did not get their 10-minute run. These programs could score more with more time, and the table below shows them as "—".
- **No further seeds.** Randomized programs have one seed, and those with invalid output did not get 3 more. A different seed could score higher.
- **90 repositories have no score from us.** 18 do not build here and 72 gave no valid output in our setup. Some of these failures may come from our setup rather than the program. Their stored outputs score at most 3,050,544, below the 5% line, but stored outputs may not be their best.
- **`mentorship-teamwork-dataset_shefketbylykbashi` was not run.** Its solvers are the Nanored solvers with a time limit.

Among the screened programs, the best outside the two kept lines are `HashCode2022_Ryan0v0` `main.py` at 3,317,323, `Google-HashCodes_Kacper-Lis` `src/c2022/Main.java` at 3,182,824, `hashcode2022_Dovgalyuk` `main.cpp` at 3,011,675. None is first on an instance, and all are below 4,009,224.

## Screen scores

One run per instance at the 5-minute limit. "—" means no valid output. `MicroEvolve` and Nanored appear here with their screen scores, which are lower than the Kept table where a program needed more than 5 minutes.

| Repository | Program | B | C | D | E | F | Sum |
|---|---|---:|---:|---:|---:|---:|---:|
| `MicroEvolve_uran-lajci` | `best_solvers/d.cpp` | 1,011,820 | 251,174 | 2,853,365 | — | — | 4,116,359 |
| `HashCode2022_Nanored4498` | `2022/Qualif/c.cpp` | 1,011,400 | 242,898 | 2,608,736 | — | — | 3,863,034 |
| `MicroEvolve_uran-lajci` | `best_solvers/c.cpp` | 870,109 | 285,714 | 608,260 | 1,274,032 | 539,585 | 3,577,700 |
| `HashCode2022_Nanored4498` | `2022/Qualif/e.cpp` | 894,161 | 110,356 | 372,996 | 1,648,976 | 483,104 | 3,509,593 |
| `HashCode2022_Ryan0v0` | `main.py` | 743,841 | 256,852 | 133,020 | 1,588,051 | 595,559 | 3,317,323 |
| `HashCode2022_Nanored4498` | `2022/Qualif/d.cpp` | 1,032,469 | — | 2,178,519 | — | — | 3,210,988 |
| `Google-HashCodes_Kacper-Lis` | `src/c2022/Main.java` | 743,829 | 224,772 | 91,424 | 1,587,891 | 534,908 | 3,182,824 |
| `hashcode2022_Dovgalyuk` | `main.cpp` | 800,067 | 121,474 | 173,626 | 1,640,454 | 276,054 | 3,011,675 |
| `hashcode-qual-2022_AlexeyZhuravlev` | `src/dima.cpp` | 436,377 | 199,330 | 81,076 | 1,626,263 | 599,037 | 2,942,083 |
| `hashcode2022_tweedegolf` | `src/main.rs` | 448,047 | 121,770 | 87,143 | 1,640,096 | 456,046 | 2,753,102 |
| `icpc-hashcode2022_marianocrosetti` | `solution_marian.cpp` | 448,047 | 116,018 | 87,143 | 1,639,790 | 442,690 | 2,733,688 |
| `Google-HashCode-2022-Solutions_mahmoudjobeel1` | `C - Collaboration.java` | 395,788 | 196,300 | 86,148 | 1,507,310 | 547,985 | 2,733,531 |
| `GHC22Qualification_slybach` | `src/main.cpp` | 800,968 | 141,902 | 167,124 | 1,600,889 | — | 2,710,883 |
| `icpc-hashcode2022_marianocrosetti` | `solution.cpp` | 378,312 | 169,010 | 67,487 | 1,637,258 | 451,205 | 2,703,272 |
| `hashcode2022_gleb-kov` | `solutions/e.cpp` | 743,839 | 201,051 | 133,020 | 1,596,245 | — | 2,674,155 |
| `google-hashcode-2022_AnkilP` | `sol.cpp` | 561,535 | 188,933 | 87,510 | 1,309,760 | 508,181 | 2,655,919 |
| `hashcode-2022-qualification_prague-pandas` | `python/main.py` | 799,717 | 7,984 | 118,067 | 1,639,102 | 76,432 | 2,641,302 |
| `hashcode2022_angelo-rendina-prima` | `src/main.rs` | 743,819 | 177,806 | 91,424 | 1,592,046 | — | 2,605,095 |
| `hashcode_2022_Nicolaus93` | `src/solution.py` | 310,676 | 150,953 | 50,530 | 1,637,258 | 453,200 | 2,602,617 |
| `hashcode2022_mullerpeter` | `main.py` | 800,256 | 220,126 | 173,626 | 1,340,878 | — | 2,534,886 |
| `GoogleHashcode2022_IgorSchittekat` | `main2.py` | 742,848 | 0 | 126,518 | 1,637,258 | 16,041 | 2,522,665 |
| `hash-code-2022_hexmod` | `src/main.py` | 742,632 | 4,562 | 91,424 | 1,637,258 | 6,983 | 2,482,859 |
| `hashcode2022_n-sc` | `Problem/main_v2.cpp` | 310,676 | 115,025 | 50,530 | 1,598,105 | 387,148 | 2,461,484 |
| `Hashcode2022_vixel-iiitd` | `Try2.cpp` | 743,819 | — | 126,518 | 1,590,069 | — | 2,460,406 |
| `hashcode2022_arnodeceuninck` | `main.py` | 616,517 | 21,783 | 90,844 | 1,639,934 | 25,249 | 2,394,327 |
| `hashcode-2022_antroseco` | `main.py` | 743,060 | 147,480 | 133,020 | 1,288,112 | 80,417 | 2,392,089 |
| `Hashcode2022_drlc` | `src/base_practice/main.py` | 743,781 | — | 91,424 | 1,554,049 | — | 2,389,254 |
| `Google-HashCode-2022-Solutions_mahmoudjobeel1` | `E - Exceptional skills.java` | 378,312 | 149,238 | 67,487 | 1,637,258 | 123,751 | 2,356,046 |
| `hashCode2022_Epado` | `index.js` | 743,000 | 6,184 | 91,111 | 1,255,687 | 226,272 | 2,322,254 |
| `hashcode2022_arnodeceuninck` | `main2.py` | 310,676 | 21,783 | 54,835 | 1,637,258 | 231,365 | 2,255,917 |
| `icpc-hashcode2022_marianocrosetti` | `out_value/solution_marian.cpp` | 518,374 | 232,739 | 85,971 | 1,345,006 | — | 2,182,090 |
| `Google-hashcode2022_FreekDS` | `solver_thibaut.py` | 742,151 | 22,212 | 91,424 | 1,233,968 | 91,065 | 2,180,820 |
| `hashcode2022_kisel-dv` | `kisel-dv/12321.py` | 310,676 | 161,169 | 54,835 | 1,301,110 | 337,053 | 2,164,843 |
| `hashcode2022_kisel-dv` | `kisel-dv/main.py` | 378,312 | 2,117 | 67,487 | 1,637,258 | 66,700 | 2,151,874 |
| `GoogleHashCode2022-Mentorship-and-Teamwork-MessyVer_0CodeLife0` | `Program.cs` | 400,660 | 0 | 68,303 | 1,634,875 | 214 | 2,104,052 |
| `icpc-hashcode2022_marianocrosetti` | `out_fruta/solution_marian.cpp` | 376,316 | — | 80,523 | 1,640,378 | — | 2,097,217 |
| `GoogleHashcode2022_IgorSchittekat` | `main.py` | 378,312 | 0 | 64,310 | 1,637,258 | 15,887 | 2,095,767 |
| `hashcode2022_arberaga` | `src/main.java` | 378,312 | 0 | 64,310 | 1,637,258 | 9,862 | 2,089,742 |
| `hashcode-2022_amanroy2001` | `main.py` | 742,712 | 2,686 | 91,424 | 1,223,438 | 29,392 | 2,089,652 |
| `hashcode-2022-qualification_prague-pandas` | `ruby/first.rb` | 310,676 | 30,749 | 54,835 | 1,637,258 | 9,862 | 2,043,380 |
| `HashCode2022_svenfinke` | `HashCodeImplementation.ipynb` | 310,676 | 0 | 54,835 | 1,637,258 | 9,862 | 2,012,631 |
| `google-hash-code-2022_mkromkamp` | `src/HashCode/Program.cs` | 310,676 | 0 | 54,835 | 1,637,258 | 9,862 | 2,012,631 |
| `HashCode2022_Ryan0v0` | `foo.py` | 310,676 | 0 | 54,835 | 1,637,108 | 4,463 | 2,007,082 |
| `g_hashcodes_kobr4` | `hashcode_qualif_2022/solver/h22.c` | 346,457 | 105,890 | 63,892 | 1,301,903 | 188,938 | 2,007,080 |
| `HashCode2022_atharv-patil` | `HashCode2022.py` | 275,518 | 0 | 45,860 | 1,637,258 | 8,025 | 1,966,661 |
| `hashcode-2022_ambolt314` | `crapgorithm.py` | 275,518 | — | 45,860 | 1,637,258 | — | 1,958,636 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_with_roles_with_lvl_up/code.py` | 310,676 | 22,726 | 54,835 | 1,300,714 | 248,250 | 1,937,201 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_with_roles/code.py` | 310,676 | 22,726 | 54,835 | 1,300,714 | 248,250 | 1,937,201 |
| `HashCoder2022_srikanth-iyengar` | `Srikanth/A.cpp` | 373,044 | 24,664 | 63,173 | 1,221,624 | 243,367 | 1,925,872 |
| `Hashcode-2022_Byooks` | `Round 1/Round 1.ipynb` | 564,858 | 2,686 | 92,994 | 1,212,993 | 40,266 | 1,913,797 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_with_roles_and_levels/code.py` | 310,676 | 4,604 | 54,835 | 1,270,158 | 248,086 | 1,888,359 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_with_roles_and_levels_with_lvl_up/code.py` | 310,676 | 4,604 | 54,835 | 1,270,158 | 248,086 | 1,888,359 |
| `Google-HashCode-2022_MihailoGrbic` | `base_jenko.py` | 382,732 | 18,034 | 62,154 | 1,300,679 | 118,314 | 1,881,913 |
| `hashcode2022_Damzwan` | `main.py` | 216,270 | — | 54,835 | 1,608,547 | — | 1,879,652 |
| `hashcode2022_kanko-ghosh` | `hashcode.cpp` | 310,676 | 24,664 | 54,835 | 1,221,624 | 243,367 | 1,855,166 |
| `hashcode2022_gnitsua` | `main.py` | 310,676 | 6,184 | 54,835 | 1,255,687 | 226,272 | 1,853,654 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_reverse/code.py` | 310,676 | 24,664 | 54,835 | 1,218,533 | 242,449 | 1,851,157 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_with_lvl_up/code.py` | 310,676 | 24,664 | 54,835 | 1,217,344 | 242,449 | 1,849,968 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_with_roles_and_levels_but_high_levels_first/code.py` | 310,676 | 25,838 | 54,835 | 1,232,573 | 226,006 | 1,849,928 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio_with_roles_and_levels_but_high_levels_first_with_lvl_up/code.py` | 310,676 | 25,838 | 54,835 | 1,232,573 | 226,006 | 1,849,928 |
| `hashcode-2022_onshimiye` | `solution.py` | 275,518 | 24,664 | 45,860 | 1,218,533 | 251,474 | 1,816,049 |
| `hashcode2022_arnodeceuninck` | `main_mateo.py` | 310,676 | 594 | 54,835 | 1,301,549 | 120,567 | 1,788,221 |
| `hashcode2022_micaelafonso` | `App.java` | 284,939 | 71,931 | 54,835 | 1,122,904 | 243,174 | 1,777,783 |
| `HashCode2022_sebastienD` | `main.go` | 412,603 | 7,801 | 78,637 | 1,223,438 | 40,698 | 1,763,177 |
| `hashcode22_belmind` | `main.py` | 310,676 | 4,599 | 54,835 | 1,324,440 | 16,950 | 1,711,500 |
| `HashCode2022_uek06` | `src/main/java/com/thales/Main.java` | 354,841 | 3,087 | 73,131 | 1,229,310 | 29,392 | 1,689,761 |
| `Hashcode2022-ARRY_YAGNESSHETTY` | `hash.cpp` | 310,676 | 21,783 | 54,835 | 1,250,613 | 44,437 | 1,682,344 |
| `MicroEvolve_uran-lajci` | `best_solvers/e.cpp` | 942,383 | 39,231 | 673,268 | — | — | 1,654,882 |
| `HashCode2022_HarveyBrezinaConniffe` | `SimplestSolution.py` | 296,983 | 5,471 | 54,835 | 1,223,438 | 52,432 | 1,633,159 |
| `Google-HashCode-2022_Curs3W4ll` | `hashcode2022_opti.py` | 310,676 | 21,783 | 54,835 | 1,243,031 | — | 1,630,325 |
| `hashcode-2022-feb_VehpuS` | `naive_2/code.py` | 310,676 | 2,686 | 54,835 | 1,223,438 | 38,508 | 1,630,143 |
| `hashcode-2022-feb_VehpuS` | `ordered_by_profit_ratio/code.py` | 310,676 | 385 | 54,835 | 1,231,081 | 26,684 | 1,623,661 |
| `Hashcode2022_SanchitaMishra170676` | `Code/code-initial.cpp` | 310,676 | 2,686 | 54,835 | 1,223,438 | 29,392 | 1,621,027 |
| `hashcode_2022_Cthulhus-Knights` | `index.js` | 414,013 | 6,346 | 61,117 | 1,059,537 | 78,106 | 1,619,119 |
| `Google-HashCode-2022_Curs3W4ll` | `hashcode2022.py` | 310,676 | 2,686 | 54,835 | 1,223,438 | — | 1,591,635 |
| `hashcode2022_otikev` | `src/com/otikev/hashcode/Main.java` | 310,676 | 2,686 | 50,530 | 1,223,438 | — | 1,587,330 |
| `hashcode-2022-qualification-round_HuzaifaIrfan-DSA` | `bruteforce.py` | 275,518 | 2,686 | 45,860 | 1,223,438 | 29,392 | 1,576,894 |
| `Google_Hashcode_2022_shemetz` | `src/mains/main_itamar.py` | 799,366 | — | 173,626 | 501,413 | 94,664 | 1,569,069 |
| `hashcode2022_Dovgalyuk` | `f.cpp` | 799,107 | 5,776 | 167,124 | 490,266 | 82,076 | 1,544,349 |
| `hashcode2022_laurerunser` | `src/Main.java` | 743,765 | 90,449 | 91,424 | 529,221 | — | 1,454,859 |
| `HashCode_mcieno` | `22-Mentorship-and-Teamwork/main.go` | 901,183 | 232,701 | 242,476 | — | — | 1,376,360 |
| `google-hashcode-2022_waltherjochen` | `src/app.ts` | 93,849 | 0 | 2,641 | 1,223,438 | 0 | 1,319,928 |
| `google-hashcode-2018-qualifier_Noobgam` | `something.cpp` | 901,153 | 154,428 | 251,751 | — | — | 1,307,332 |
| `HashCode2022_Nanored4498` | `2022/Qualif/f.cpp` | 870,345 | 273,810 | 119,838 | — | — | 1,263,993 |
| `MicroEvolve_uran-lajci` | `best_solvers/f.cpp` | 870,345 | 227,572 | 119,838 | — | — | 1,217,755 |
| `hashcode2022_sbrodehl` | `Qualification Round/main.py` | 800,991 | 156,988 | 173,626 | — | — | 1,131,605 |
| `Google-Hashcode-2022-Mentorship-and-Teamwork_khalilghouddan` | `algo_glt.py` | 800,991 | 147,551 | 167,124 | — | — | 1,115,666 |
| `MicroEvolve_uran-lajci` | `best_solvers/b.cpp` | 1,057,446 | — | — | — | — | 1,057,446 |
| `hashcode-2022_amanroy2001` | `main.go` | 289,211 | 111,047 | 54,835 | 477,132 | 123,242 | 1,055,467 |
| `hashcode-qual-2022_AlexeyZhuravlev` | `src/lexa.cpp` | 798,459 | 80,491 | 173,626 | — | — | 1,052,576 |
| `qualification-round-2022_Gophing-Around` | `main.go` | 743,702 | 160,343 | 126,518 | — | — | 1,030,563 |
| `google-hashcode-2021_Superbasil3` | `solution.py` | 800,930 | 46,547 | 173,626 | — | — | 1,021,103 |
| `HashCode2022_Nanored4498` | `2022/Qualif/ab.cpp` | 1,003,496 | — | — | — | — | 1,003,496 |
| `hashcode-2022_orsa-scholis` | `src/main.rs` | 743,815 | 95,407 | 133,020 | — | — | 972,242 |
| `hashcode_vikds` | `2022/cpp/src/main.cpp` | 743,841 | 44,788 | 91,424 | — | — | 880,053 |
| `hashCode2022_RideSVEL` | `main.py` | 743,841 | — | 133,020 | — | — | 876,861 |
| `qualification_round_2022_HashCode-ICL-2022` | `naive.py` | 800,991 | 0 | 61,994 | — | — | 862,985 |
| `hashcode-2022_MuhammedHasan` | `src/main.py` | 606,248 | 153,665 | 101,567 | 0 | 0 | 861,480 |
| `hashcode2022_opiechow` | `team.py` | 743,821 | — | 91,424 | — | — | 835,245 |
| `icpc-hashcode2022_marianocrosetti` | `out_frutero_frutero/solution_marian_fruta.cpp` | 726,926 | — | 108,008 | — | — | 834,934 |
| `HashCodeQualification2022_quangminhdinh` | `src/Processor.java` | 800,991 | — | — | — | — | 800,991 |
| `icpc-hashcode2022_marianocrosetti` | `solution_marian_fruta.cpp` | 500,365 | 193,359 | 81,973 | — | — | 775,697 |
| `Optimizational-Problems-Solutions_indjev99` | `mentorship_and_teamwork.cpp` | 714,087 | — | — | — | — | 714,087 |
| `Google-HashCode-2022-Solutions_mahmoudjobeel1` | `D - Dense schedule.java` | 574,702 | — | 116,228 | — | — | 690,930 |
| `Google-HashCode-2022-Solutions_mahmoudjobeel1` | `B - Better start small.java` | 651,066 | — | — | — | — | 651,066 |
| `icpc-hashcode2022_marianocrosetti` | `out_before/solution_marian.cpp` | 414,093 | 135,849 | 80,523 | — | — | 630,465 |
| `icpc-hashcode2022_marianocrosetti` | `out_before_takes/solution_marian.cpp` | 414,093 | 113,574 | 80,523 | — | — | 608,190 |
| `hashcode2022_masterchief164` | `code.cpp` | 264,115 | 6,680 | 34,325 | 274,138 | 0 | 579,258 |
| `google-hashcode_ch-pat` | `hashcode-2022/main.py` | 570,269 | — | — | — | — | 570,269 |
| `hashcode-2022_ambolt314` | `main.py` | 542,287 | — | — | — | — | 542,287 |
| `hashcode2022_jjustin` | `main.py` | 280,463 | 52,184 | 90,392 | 77,537 | 38,168 | 538,744 |
| `HashCode_nzacha` | `2022/index.ts` | 310,676 | 74,408 | 54,835 | 71,339 | — | 511,258 |
| `hashcode2022_wuttem` | `solve_mw.py` | 346,457 | 16,837 | 49,052 | 29,807 | 4,650 | 446,803 |
| `hashcode2022_Dabsunter` | `knowledge.py` | 310,676 | — | 54,835 | — | — | 365,511 |
| `Hashcode-2022_Cmathou` | `grid.py` | 296,983 | — | 50,165 | — | — | 347,148 |
| `hashcode2022_n-sc` | `Problem/Abgabe.py` | 296,983 | — | 50,165 | — | — | 347,148 |
| `Hashcode2022_SanchitaMishra170676` | `Code/Code-final.cpp` | 346,457 | — | — | — | — | 346,457 |
| `hashcode2022_n-sc` | `Problem/main.cpp` | 289,211 | — | 54,835 | — | — | 344,046 |
| `HASHCODE_2022_cristina-georgeta-radu` | `Source.cpp` | 73,409 | 137,994 | 34,291 | 46,687 | 38,449 | 330,830 |
| `HashCode-2022_Andree37` | `main.py` | 107,186 | 67,997 | 52,602 | 42,569 | 28,679 | 299,033 |
| `hashcode_2022_StefPler` | `projectDistributions.py` | 48,997 | 83,418 | 29,999 | 35,709 | 29,109 | 227,232 |
| `Hashcode-2022_Cmathou` | `main.py` | 48,997 | 78,737 | 29,999 | 35,709 | 29,109 | 222,551 |
| `Hash-code-2022-astrasterix_aymenkhs` | `main.py` | 48,997 | 83,418 | 29,999 | 35,709 | 2,537 | 200,660 |
| `hashcode-2022_tallosim` | `main.py` | 0 | 109,411 | 1,010 | — | — | 110,421 |
| `hashcode-2022_tallosim` | `notebook.ipynb` | 0 | 109,411 | 1,010 | — | — | 110,421 |
| `hashcode-2022_tallosim` | `main2.py` | 16,512 | 30,749 | 13,217 | 7,188 | 0 | 67,666 |
| `hashcode2022_idow09` | `main.py` | 25,771 | — | — | — | — | 25,771 |
| `hashcode-2022-feb_VehpuS` | `naive_1/code.py` | 7,950 | 151 | 216 | 349 | 4,649 | 13,315 |
| `hash-code-2022_jcolladosp` | `qualification_round/src/main.ts` | 1,518 | — | 216 | — | — | 1,734 |
| `Google-Hashcode-2022-Solution_chrisxu333` | `main.cpp` | — | — | 0 | — | — | 0 |
| `Google-Hash-Code-Qualification-Round-Codes_kayacanv` | `2022_hashcode/sol.cpp` | 0 | 0 | 0 | 0 | 0 | 0 |
| `HashCode-2022_iheb-haddad` | `ourproject.cpp` | — | — | 0 | — | — | 0 |
| `Hashcode-2022-my-solution-A-F_mayhim182` | `hash (3).cpp` | — | — | — | — | — | 0 |
| `hashcode2022_gleb-kov` | `solutions/d.cpp` | 0 | — | — | 0 | 0 | 0 |
| `hashcode2022_gleb-kov` | `solutions/b.cpp` | — | 0 | 0 | — | — | 0 |
| `Hashcode-2022-my-solution-A-F_mayhim182` | `hash (5).cpp` | — | — | — | — | — | 0 |
| `Hashcode-2022-my-solution-A-F_mayhim182` | `hash.cpp` | — | — | — | — | — | 0 |
| `hashcode2022_gleb-kov` | `solutions/c.cpp` | — | — | 0 | 0 | — | 0 |
| `hashcode2022_gleb-kov` | `solutions/f.cpp` | — | 0 | 0 | 0 | 0 | 0 |
| `icpc-hashcode2022_marianocrosetti` | `algorithms/onepizza_example.cpp` | — | — | — | — | — | 0 |
| `hashcode2022_wuttem` | `solve_ao.py` | — | — | — | — | — | 0 |
| `hashcode2022_IumoInfinium` | `main.py` | 0 | — | — | — | — | 0 |
| `Google-Hashcode-2022_grandmasteri` | `main.py` | — | — | — | — | — | 0 |
| `mentorship-and-teamwork_m-baj` | `src/neighbor_main.py` | — | — | — | — | — | 0 |
| `HashCode2022_MaximeFre` | `src/main.py` | — | — | — | — | — | 0 |
| `HashCode2022_Shrirang97` | `HashCode.py` | — | 0 | — | — | 0 | 0 |
| `GoogleHashcode2022_HakimTem` | `Hashcode/hashcode.py` | — | — | — | — | — | 0 |
| `Hashcode2022_vixel-iiitd` | `Try1.cpp` | — | — | — | — | — | 0 |
| `Hashcode2022_pizzahunter2000` | `src/Attribution.java` | — | — | — | — | — | 0 |
| `Mentorship-And-Teamwork-Optimization-C_bouchouk` | `main.c` | — | — | — | — | — | 0 |
| `Hashcode2022_BlaisMathieu` | `hashcode.py` | — | — | — | — | — | 0 |
| `HashCode2022_Shrirang97` | `Test.ipynb` | — | 0 | — | — | 0 | 0 |
| `hashcode2022_iamayushanand` | `bajaj/Ide.cpp` | — | — | — | — | — | 0 |
| `hashcode2022_javgat` | `team_greedy.py` | — | — | — | — | — | 0 |
| `Hashcode_2022_attempt_SaNDy4ortyFivE` | `main.py` | — | — | — | — | — | 0 |
| `TPM_Teamwork-with-Mentoring-Problem_GVS2001` | `src/IC_resultados.ipynb` | — | — | — | — | — | 0 |
| `hashcode_DjellalAbdou` | `index.js` | — | — | — | — | — | 0 |
| `hashcode_Ruchit-rt` | `main.py` | — | 0 | — | — | — | 0 |
| `hashcode-2022-gdgfi_fabian57fabian` | `main.py` | — | — | 0 | — | — | 0 |
| `mentorship-and-teamwork_m-baj` | `src/evo_main.py` | — | — | — | — | — | 0 |

## Repositories not run

| Repository | Why | Stored outputs |
|---|---|---:|
| `hashcode2022_xoposhiy` | no program gave a valid output in our setup | 3,050,544 |
| `HashCode2022_isaaclo97` | no program gave a valid output in our setup | 2,942,362 |
| `HashCode2022_alvarocrego` | no program gave a valid output in our setup | 2,515,482 |
| `hashcode2022_englhardt` | no program gave a valid output in our setup | 2,442,047 |
| `hashcode-2022_HasinduLanka` | no program gave a valid output in our setup | 1,701,655 |
| `hashcode2022_kirankuyate2157` | no program gave a valid output in our setup | 1,663,984 |
| `Hashcode2022_rotolonico` | no program gave a valid output in our setup | 1,405,081 |
| `GoogleHashCode2022-Mentorship-and-Teamwork_0CodeLife0` | no program gave a valid output in our setup | 1,245,051 |
| `google_hashcode_2022_Bhdzhdz` | does not build here | 1,199,089 |
| `Hashcode2k22_Javariati` | no program gave a valid output in our setup | 800,955 |
| `Mentorship_Teamwork_ILS_elvirmisini` | does not build here | 498,039 |
| `HashCode2022_NikosGour` | no program gave a valid output in our setup | 346,457 |
| `hashcode2022_ootks` | no program gave a valid output in our setup | 334,157 |
| `HashCode2022_ShahilPatel-IITDh` | no program gave a valid output in our setup | 275,518 |
| `google-hashcode-2022_baptistelebail` | no program gave a valid output in our setup | 154,040 |
| `2021-hashcode-practice_spes2357` | no program gave a valid output in our setup | — |
| `Google-HashCode2022_samihoucheimi` | no program gave a valid output in our setup | — |
| `Google-Hashcode-2022_Blisteur` | does not build here | — |
| `Google-Hashcode-2022_Cr4ftingMine` | no program gave a valid output in our setup | — |
| `Google-Hashcode-2022_umang4846` | no program gave a valid output in our setup | — |
| `Google-Hashcode2022_ginuxone` | no program gave a valid output in our setup | — |
| `Google-hash-code-2022_Am0stafa` | no program gave a valid output in our setup | — |
| `GoogleHashCode-22_navasmdc` | does not build here | — |
| `GoogleHashCode2022_Jdawson03` | no program gave a valid output in our setup | — |
| `GoogleHashCode_damiano00` | no program gave a valid output in our setup | — |
| `GoogleHashcode-2022-Solution_pradeeprajm01` | no program gave a valid output in our setup | — |
| `HashCode-2022_MIA-Deltat1995` | no program gave a valid output in our setup | — |
| `HashCode2022Qualification_SmashKs` | does not build here | — |
| `HashCode2022Solution_ootisg` | does not build here | — |
| `HashCode2022_AlfonsoSarroLarrey` | no program gave a valid output in our setup | — |
| `HashCode2022_CorwinMangin` | does not build here | — |
| `HashCode2022_GoogleHashcode2022-JSBad` | no program gave a valid output in our setup | — |
| `HashCode2022_ImadABID` | does not build here | — |
| `HashCode2022_TheGuyWithoutH` | does not build here | — |
| `HashCode2022_Traderain` | no program gave a valid output in our setup | — |
| `HashCode2022_YusifAghalar` | does not build here | — |
| `HashCode2022_fpallaro` | no program gave a valid output in our setup | — |
| `HashCode2022_gamaticow` | no program gave a valid output in our setup | — |
| `HashCode2022_n-gutierrez` | no program gave a valid output in our setup | — |
| `HashCode22_AdRs21` | no program gave a valid output in our setup | — |
| `HashCode22_g-bl` | no program gave a valid output in our setup | — |
| `HashCode_2022_abhishr06` | no program gave a valid output in our setup | — |
| `HashCode_2022_alibimm` | no program gave a valid output in our setup | — |
| `Hashcode-2021_The-Crystal-Devs` | does not build here | — |
| `Hashcode-2022_MrTooOldDriver` | does not build here | — |
| `Hashcode_2022_lynparbone` | no program gave a valid output in our setup | — |
| `Mentorship-and-Teamwork---Hash-Code-2022-Qualification_Abhishek-1087` | no program gave a valid output in our setup | — |
| `Team-Manager_ShifaKhan33` | no program gave a valid output in our setup | — |
| `google-hashcode-2022_marc1404` | no program gave a valid output in our setup | — |
| `google-hashcode-2022_mhmd-azeez` | no program gave a valid output in our setup | — |
| `google-hashcode-2022_samuelebortolotti` | no program gave a valid output in our setup | — |
| `googleCodeHash_dasamantaraoaditya` | no program gave a valid output in our setup | — |
| `hascode_mmarouen` | no program gave a valid output in our setup | — |
| `hash-code-2022_M3A-Team` | no program gave a valid output in our setup | — |
| `hashCode2022_Tom-stack3` | no program gave a valid output in our setup | — |
| `hash_code_2022_nvog1` | does not build here | — |
| `hashcode-2021_djefrey` | no program gave a valid output in our setup | — |
| `hashcode-2022-alambik_clementbegnaud` | no program gave a valid output in our setup | — |
| `hashcode-2022-attempts_achingachris` | no program gave a valid output in our setup | — |
| `hashcode-2022-qualif_joffrey-bion` | does not build here | — |
| `hashcode-2022-qualification_schweikart` | no program gave a valid output in our setup | — |
| `hashcode-2022_Knackie` | does not build here | — |
| `hashcode-2022_RobbeDP` | no program gave a valid output in our setup | — |
| `hashcode-2022_SaffatHasan` | no program gave a valid output in our setup | — |
| `hashcode-2022_christianwiese` | no program gave a valid output in our setup | — |
| `hashcode-2022_florin141` | does not build here | — |
| `hashcode-2022_justsolomon` | no program gave a valid output in our setup | — |
| `hashcode-2022_krmbzds` | no program gave a valid output in our setup | — |
| `hashcode-2022_muety` | no program gave a valid output in our setup | — |
| `hashcode-2022_theamankumarsingh` | no program gave a valid output in our setup | — |
| `hashcode2022_JDOsborne1` | no program gave a valid output in our setup | — |
| `hashcode2022_Kitarsh` | no program gave a valid output in our setup | — |
| `hashcode2022_Phylu` | no program gave a valid output in our setup | — |
| `hashcode2022_albheim` | no program gave a valid output in our setup | — |
| `hashcode2022_dzjkb` | no program gave a valid output in our setup | — |
| `hashcode2022_katie-hughes` | no program gave a valid output in our setup | — |
| `hashcode2022_kindermoumoute` | does not build here | — |
| `hashcode2022_noharms` | no program gave a valid output in our setup | — |
| `hashcode2022_ogtayhuseynov0` | no program gave a valid output in our setup | — |
| `hashcode2022_pblkt` | no program gave a valid output in our setup | — |
| `hashcode2022_yasardeniz9` | does not build here | — |
| `hashcode22-EVREST_simbarras` | no program gave a valid output in our setup | — |
| `hashcode_2022_Mifour` | no program gave a valid output in our setup | — |
| `hashcode_2022_davimatyi` | no program gave a valid output in our setup | — |
| `hashcode_2022_peirisabhi` | no program gave a valid output in our setup | — |
| `hashcode_2022_qualification_miksax` | no program gave a valid output in our setup | — |
| `hashcode_22_tibovanheule` | no program gave a valid output in our setup | — |
| `hashcode_cyril-sabourault` | no program gave a valid output in our setup | — |
| `hashcode_floriandejonckheere` | no program gave a valid output in our setup | — |
| `team-assignment-optimizer_giorgos1998` | no program gave a valid output in our setup | — |

## Run setup

See the [scores of `llm_evolved_greedy`](output/llm_evolved_greedy/scores.md) and [of `instance_specific_greedy`](output/instance_specific_greedy/scores.md). Code changes were limited to the seed, input and output paths and compatibility fixes, in work copies only. The `solvers/` copies are unpatched.
