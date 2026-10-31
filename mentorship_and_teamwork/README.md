# Mentorship and Teamwork

Google Hash Code 2022, Qualification round.

Problem statement and inputs: [pierreavn/google-hashcode-archive/archive/2022/qualification](https://github.com/pierreavn/google-hashcode-archive/tree/main/archive/2022/qualification).

## Why only two solvers

Two solvers are kept out of 196 repositories. A solver is kept if it is first on an instance, or if the sum of its per-instance means is within 5% of the best total in the competition (at least 4,009,224, 95% of 4,220,236). All usable programs got a screen on instances B–F with one seed and a 5-minute limit. The kept repositories' programs were then run at the 10-minute limit. The other programs did not get the 10-minute or 10-seed runs, so they are compared only by the screen. The rule, the scores and what was not run are in [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md). The kept solvers live in [`solvers/`](solvers/) under method names, with their outputs in [`output/`](output/). Kept: `MicroEvolve`, first on all five instances, and `mentorship-teamwork`, a refactor of Nanored's solvers, which reaches the 5% line. The other repositories are listed under *Removed after benchmarking* below.

## Collected solvers

2 solvers: 2 documented by hand (details below the tables) and 0 imported in bulk from GitHub.

### Documented by hand

| Folder | Language | Reported result |
|---|---|---|
| [`solvers/instance_specific_greedy`](solvers/instance_specific_greedy/) | C++ | README: B 1,032,469, C 255,918, D 2,608,736, E 1,648,976, F 542,013, with A 33 (6,088,145) |
| [`solvers/llm_evolved_greedy`](solvers/llm_evolved_greedy/) | C++ (+ Python method) | Our runs: B 1,057,446, C 285,714, D 2,853,365, E 1,656,494, F 1,381,929 (7,234,948) |

### [`solvers/instance_specific_greedy/`](solvers/instance_specific_greedy/)

- **Source:** https://github.com/uran-lajci/mentorship-teamwork
- **Snapshot:** GitHub clone of branch `main` at commit `9b365f3` (history 2022-02-25 → 2026-06-26); `.git` removed on import. MIT licensed.
- **Origin:** Refactor of [Nanored4498/HashCode2022](https://github.com/Nanored4498/HashCode2022) (team Quiche LORIAinne), with a time limit and capacity and parsing fixes.
- **Authors:** Yoann Coudert--Osmont (Nanored4498); refactor by uran-lajci
- **Language:** C++
- **Approach:** Five greedy programs, `b` to `f`, each with its own rule for which project to commit next.
- **Scores:** The repo's README: 6,088,145 over A–F, taking the best program per instance. Our runs of `f.cpp` score higher on C and F.
- **Bundled inputs:** None bundled.
- **Run:** `g++ -O3 -std=c++20 -o solve solvers/f.cpp`, then `./solve < input > output`
- **Benchmark:** B 1,032,469, C 273,810, D 2,608,736, E 1,648,976, F 899,143 (6,463,134), best program per instance ([scores](output/instance_specific_greedy/scores.md)).

### [`solvers/llm_evolved_greedy/`](solvers/llm_evolved_greedy/)

- **Source:** https://github.com/uran-lajci/MicroEvolve
- **Snapshot:** GitHub clone at commit `7e5abc2` (2026-08-15); `.git` removed on import.
- **Origin:** Post-contest project.
- **Authors:** uran-lajci
- **Language:** C++ solvers, Python method
- **Approach:** An LLM proposes small edits to a strong greedy solver, and each edit is kept only if the score on that instance improves. One program per instance, in `best_solvers/`.
- **Bundled inputs:** None bundled.
- **Run:** `g++ -O3 -std=c++20 -o solve best_solvers/f.cpp`, then `./solve < input > output`
- **Benchmark:** B 1,057,446, C 285,714, D 2,853,365, E 1,656,494, F 1,381,929 (7,234,948), first on all five, using the program for each instance ([scores](output/llm_evolved_greedy/scores.md)). The E and F runs took 448 s and 574 s with only two programs running; with six at once they did not finish within 10 minutes.

## Removed after benchmarking

These 194 repositories were screened or examined on 2026-10-31 and then deleted from the collection (see *Why only two solvers* above). *Screen only* means one run per instance at a 5-minute limit. *Not run* means no program of the repository produced a score here, so nothing is known about it beyond any stored outputs. Sources are linked; [`SOLVER_SELECTION.md`](SOLVER_SELECTION.md) has the scores. The last entry was never collected: it was examined at import and holds no solver.

- `2021-hashcode-practice_spes2357` (https://github.com/spes2357/2021-hashcode-practice): not run: no program gave a valid output in our setup, and it stores no valid output.
- `GHC22Qualification_slybach` (https://github.com/slybach/GHC22Qualification): screen only: best program `src/main.cpp` totals 2,710,883, and none is first on an instance.
- `Google-Hash-Code-Qualification-Round-Codes_kayacanv` (https://github.com/kayacanv/Google-Hash-Code-Qualification-Round-Codes): screen only: its program scored 0 or gave no valid output.
- `Google-HashCode-2022-Solutions_mahmoudjobeel1` (https://github.com/mahmoudjobeel1/Google-HashCode-2022-Solutions): screen only: best program `C - Collaboration.java` totals 2,733,531 (4 programs), and none is first on an instance.
- `Google-HashCode-2022_Curs3W4ll` (https://github.com/Curs3W4ll/Google-HashCode-2022): screen only: best program `hashcode2022_opti.py` totals 1,630,325 (2 programs), and none is first on an instance.
- `Google-HashCode-2022_MihailoGrbic` (https://github.com/MihailoGrbic/Google-HashCode-2022): screen only: best program `base_jenko.py` totals 1,881,913, and none is first on an instance.
- `Google-HashCode2022_samihoucheimi` (https://github.com/samihoucheimi/Google-HashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `Google-HashCodes_Kacper-Lis` (https://github.com/Kacper-Lis/Google-HashCodes): screen only: best program `src/c2022/Main.java` totals 3,182,824, and none is first on an instance.
- `Google-Hashcode-2022-Mentorship-and-Teamwork_khalilghouddan` (https://github.com/khalilghouddan/Google-Hashcode-2022-Mentorship-and-Teamwork): screen only: best program `algo_glt.py` totals 1,115,666, and none is first on an instance.
- `Google-Hashcode-2022-Solution_chrisxu333` (https://github.com/chrisxu333/Google-Hashcode-2022-Solution): screen only: its program scored 0 or gave no valid output.
- `Google-Hashcode-2022_Blisteur` (https://github.com/Blisteur/Google-Hashcode-2022): not run: does not build here, and it stores no valid output.
- `Google-Hashcode-2022_Cr4ftingMine` (https://github.com/Cr4ftingMine/Google-Hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `Google-Hashcode-2022_grandmasteri` (https://github.com/grandmasteri/Google-Hashcode-2022): screen only: its program scored 0 or gave no valid output.
- `Google-Hashcode-2022_umang4846` (https://github.com/umang4846/Google-Hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `Google-Hashcode2022_ginuxone` (https://github.com/ginuxone/Google-Hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `Google-hash-code-2022_Am0stafa` (https://github.com/Am0stafa/Google-hash-code-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `Google-hashcode2022_FreekDS` (https://github.com/FreekDS/Google-hashcode2022): screen only: best program `solver_thibaut.py` totals 2,180,820, and none is first on an instance.
- `GoogleHashCode-22_navasmdc` (https://github.com/navasmdc/GoogleHashCode-22): not run: does not build here, and it stores no valid output.
- `GoogleHashCode2022-Mentorship-and-Teamwork-MessyVer_0CodeLife0` (https://github.com/0CodeLife0/GoogleHashCode2022-Mentorship-and-Teamwork-MessyVer): screen only: best program `Program.cs` totals 2,104,052, and none is first on an instance.
- `GoogleHashCode2022-Mentorship-and-Teamwork_0CodeLife0` (https://github.com/0CodeLife0/GoogleHashCode2022-Mentorship-and-Teamwork): not run: no program gave a valid output in our setup. Its stored outputs score 1,245,051.
- `GoogleHashCode2022_Jdawson03` (https://github.com/Jdawson03/GoogleHashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `GoogleHashCode_damiano00` (https://github.com/damiano00/GoogleHashCode): not run: no program gave a valid output in our setup, and it stores no valid output.
- `GoogleHashcode-2022-Solution_pradeeprajm01` (https://github.com/pradeeprajm01/GoogleHashcode-2022-Solution): not run: no program gave a valid output in our setup, and it stores no valid output.
- `GoogleHashcode2022_HakimTem` (https://github.com/HakimTem/GoogleHashcode2022): screen only: its program scored 0 or gave no valid output.
- `GoogleHashcode2022_IgorSchittekat` (https://github.com/IgorSchittekat/GoogleHashcode2022): screen only: best program `main2.py` totals 2,522,665 (2 programs), and none is first on an instance.
- `Google_Hashcode_2022_shemetz` (https://github.com/shemetz/Google_Hashcode_2022): screen only: best program `src/mains/main_itamar.py` totals 1,569,069, and none is first on an instance.
- `HASHCODE_2022_cristina-georgeta-radu` (https://github.com/cristina-georgeta-radu/HASHCODE_2022): screen only: best program `Source.cpp` totals 330,830, and none is first on an instance.
- `Hash-code-2022-astrasterix_aymenkhs` (https://github.com/aymenkhs/Hash-code-2022-astrasterix): screen only: best program `main.py` totals 200,660, and none is first on an instance.
- `HashCode-2022_Andree37` (https://github.com/Andree37/HashCode-2022): screen only: best program `main.py` totals 299,033, and none is first on an instance.
- `HashCode-2022_MIA-Deltat1995` (https://github.com/MIA-Deltat1995/HashCode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode-2022_iheb-haddad` (https://github.com/iheb-haddad/HashCode-2022): screen only: its program scored 0 or gave no valid output.
- `HashCode2022Qualification_SmashKs` (https://github.com/SmashKs/HashCode2022Qualification): not run: does not build here, and it stores no valid output.
- `HashCode2022Solution_ootisg` (https://github.com/ootisg/HashCode2022Solution): not run: does not build here, and it stores no valid output.
- `HashCode2022_AlfonsoSarroLarrey` (https://github.com/AlfonsoSarroLarrey/HashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode2022_CorwinMangin` (https://github.com/CorwinMangin/HashCode2022): not run: does not build here, and it stores no valid output.
- `HashCode2022_GoogleHashcode2022-JSBad` (https://github.com/GoogleHashcode2022-JSBad/HashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode2022_HarveyBrezinaConniffe` (https://github.com/HarveyBrezinaConniffe/HashCode2022): screen only: best program `SimplestSolution.py` totals 1,633,159, and none is first on an instance.
- `HashCode2022_ImadABID` (https://github.com/ImadABID/HashCode2022): not run: does not build here, and it stores no valid output.
- `HashCode2022_MaximeFre` (https://github.com/MaximeFre/HashCode2022): screen only: its program scored 0 or gave no valid output.
- `HashCode2022_Nanored4498` (https://github.com/Nanored4498/HashCode2022): replaced by [instance_specific_greedy](solvers/instance_specific_greedy/), its refactor with a time limit. Its programs scored the same on what they could run, and crash on E or F where the refactor raised capacities.
- `HashCode2022_NikosGour` (https://github.com/NikosGour/HashCode2022): not run: no program gave a valid output in our setup. Its stored outputs score 346,457.
- `HashCode2022_Ryan0v0` (https://github.com/Ryan0v0/HashCode2022): screen only: best program `main.py` totals 3,317,323 (2 programs), and none is first on an instance.
- `HashCode2022_ShahilPatel-IITDh` (https://github.com/ShahilPatel-IITDh/HashCode2022): not run: no program gave a valid output in our setup. Its stored outputs score 275,518.
- `HashCode2022_Shrirang97` (https://github.com/Shrirang97/HashCode2022): screen only: no program scored above 0.
- `HashCode2022_TheGuyWithoutH` (https://github.com/TheGuyWithoutH/HashCode2022): not run: does not build here, and it stores no valid output.
- `HashCode2022_Traderain` (https://github.com/Traderain/HashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode2022_YusifAghalar` (https://github.com/YusifAghalar/HashCode2022): not run: does not build here, and it stores no valid output.
- `HashCode2022_alvarocrego` (https://github.com/alvarocrego/HashCode2022): not run: no program gave a valid output in our setup. Its stored outputs score 2,515,482.
- `HashCode2022_atharv-patil` (https://github.com/atharv-patil/HashCode2022): screen only: best program `HashCode2022.py` totals 1,966,661, and none is first on an instance.
- `HashCode2022_fpallaro` (https://github.com/fpallaro/HashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode2022_gamaticow` (https://github.com/gamaticow/HashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode2022_isaaclo97` (https://github.com/isaaclo97/HashCode2022): not run: no program gave a valid output in our setup. Its stored outputs score 2,942,362.
- `HashCode2022_n-gutierrez` (https://github.com/n-gutierrez/HashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode2022_sebastienD` (https://github.com/sebastienD/HashCode2022): screen only: best program `main.go` totals 1,763,177, and none is first on an instance.
- `HashCode2022_svenfinke` (https://github.com/svenfinke/HashCode2022): screen only: best program `HashCodeImplementation.ipynb` totals 2,012,631, and none is first on an instance.
- `HashCode2022_uek06` (https://github.com/uek06/HashCode2022): screen only: best program `src/main/java/com/thales/Main.java` totals 1,689,761, and none is first on an instance.
- `HashCode22_AdRs21` (https://github.com/AdRs21/HashCode22): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode22_g-bl` (https://github.com/g-bl/HashCode22): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCodeQualification2022_quangminhdinh` (https://github.com/quangminhdinh/HashCodeQualification2022): screen only: best program `src/Processor.java` totals 800,991, and none is first on an instance.
- `HashCode_2022_abhishr06` (https://github.com/abhishr06/HashCode_2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode_2022_alibimm` (https://github.com/alibimm/HashCode_2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `HashCode_mcieno` (https://github.com/mcieno/HashCode): screen only: best program `22-Mentorship-and-Teamwork/main.go` totals 1,376,360, and none is first on an instance.
- `HashCode_nzacha` (https://github.com/nzacha/HashCode): screen only: best program `2022/index.ts` totals 511,258, and none is first on an instance.
- `HashCoder2022_srikanth-iyengar` (https://github.com/srikanth-iyengar/HashCoder2022): screen only: best program `Srikanth/A.cpp` totals 1,925,872, and none is first on an instance.
- `Hashcode-2021_The-Crystal-Devs` (https://github.com/The-Crystal-Devs/Hashcode-2021): not run: does not build here, and it stores no valid output.
- `Hashcode-2022-my-solution-A-F_mayhim182` (https://github.com/mayhim182/Hashcode-2022-my-solution-A-F): screen only: no program scored above 0.
- `Hashcode-2022_Byooks` (https://github.com/Byooks/Hashcode-2022): screen only: best program `Round 1/Round 1.ipynb` totals 1,913,797, and none is first on an instance.
- `Hashcode-2022_Cmathou` (https://github.com/Cmathou/Hashcode-2022): screen only: best program `grid.py` totals 347,148 (2 programs), and none is first on an instance.
- `Hashcode-2022_MrTooOldDriver` (https://github.com/MrTooOldDriver/Hashcode-2022): not run: does not build here, and it stores no valid output.
- `Hashcode2022-ARRY_YAGNESSHETTY` (https://github.com/YAGNESSHETTY/Hashcode2022-ARRY): screen only: best program `hash.cpp` totals 1,682,344, and none is first on an instance.
- `Hashcode2022_BlaisMathieu` (https://github.com/BlaisMathieu/Hashcode2022): screen only: its program scored 0 or gave no valid output.
- `Hashcode2022_SanchitaMishra170676` (https://github.com/SanchitaMishra170676/Hashcode2022): screen only: best program `Code/code-initial.cpp` totals 1,621,027 (2 programs), and none is first on an instance.
- `Hashcode2022_drlc` (https://github.com/drlc/Hashcode2022): screen only: best program `src/base_practice/main.py` totals 2,389,254, and none is first on an instance.
- `Hashcode2022_pizzahunter2000` (https://github.com/pizzahunter2000/Hashcode2022): screen only: its program scored 0 or gave no valid output.
- `Hashcode2022_rotolonico` (https://github.com/rotolonico/Hashcode2022): not run: no program gave a valid output in our setup. Its stored outputs score 1,405,081.
- `Hashcode2022_vixel-iiitd` (https://github.com/vixel-iiitd/Hashcode2022): screen only: best program `Try2.cpp` totals 2,460,406 (2 programs), and none is first on an instance.
- `Hashcode2k22_Javariati` (https://github.com/Javariati/Hashcode2k22): not run: no program gave a valid output in our setup. Its stored outputs score 800,955.
- `Hashcode_2022_attempt_SaNDy4ortyFivE` (https://github.com/SaNDy4ortyFivE/Hashcode_2022_attempt): screen only: its program scored 0 or gave no valid output.
- `Hashcode_2022_lynparbone` (https://github.com/lynparbone/Hashcode_2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `Mentorship-And-Teamwork-Optimization-C_bouchouk` (https://github.com/bouchouk/Mentorship-And-Teamwork-Optimization-C): screen only: its program scored 0 or gave no valid output.
- `Mentorship-and-Teamwork---Hash-Code-2022-Qualification_Abhishek-1087` (https://github.com/Abhishek-1087/Mentorship-and-Teamwork---Hash-Code-2022-Qualification): not run: no program gave a valid output in our setup, and it stores no valid output.
- `Mentorship_Teamwork_ILS_elvirmisini` (https://github.com/elvirmisini/Mentorship_Teamwork_ILS): not run: does not build here. Its stored outputs score 498,039.
- `Optimizational-Problems-Solutions_indjev99` (https://github.com/indjev99/Optimizational-Problems-Solutions): screen only: best program `mentorship_and_teamwork.cpp` totals 714,087, and none is first on an instance.
- `TPM_Teamwork-with-Mentoring-Problem_GVS2001` (https://github.com/GVS2001/TPM_Teamwork-with-Mentoring-Problem): screen only: its program scored 0 or gave no valid output.
- `Team-Manager_ShifaKhan33` (https://github.com/ShifaKhan33/Team-Manager): not run: no program gave a valid output in our setup, and it stores no valid output.
- `g_hashcodes_kobr4` (https://github.com/kobr4/g_hashcodes): screen only: best program `hashcode_qualif_2022/solver/h22.c` totals 2,007,080, and none is first on an instance.
- `google-hash-code-2022_mkromkamp` (https://github.com/mkromkamp/google-hash-code-2022): screen only: best program `src/HashCode/Program.cs` totals 2,012,631, and none is first on an instance.
- `google-hashcode-2018-qualifier_Noobgam` (https://github.com/Noobgam/google-hashcode-2018-qualifier): screen only: best program `something.cpp` totals 1,307,332, and none is first on an instance.
- `google-hashcode-2021_Superbasil3` (https://github.com/Superbasil3/google-hashcode-2021): screen only: best program `solution.py` totals 1,021,103, and none is first on an instance.
- `google-hashcode-2022_AnkilP` (https://github.com/AnkilP/google-hashcode-2022): screen only: best program `sol.cpp` totals 2,655,919, and none is first on an instance.
- `google-hashcode-2022_baptistelebail` (https://github.com/baptistelebail/google-hashcode-2022): not run: no program gave a valid output in our setup. Its stored outputs score 154,040.
- `google-hashcode-2022_marc1404` (https://github.com/marc1404/google-hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `google-hashcode-2022_mhmd-azeez` (https://github.com/mhmd-azeez/google-hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `google-hashcode-2022_samuelebortolotti` (https://github.com/samuelebortolotti/google-hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `google-hashcode-2022_waltherjochen` (https://github.com/waltherjochen/google-hashcode-2022): screen only: best program `src/app.ts` totals 1,319,928, and none is first on an instance.
- `google-hashcode_ch-pat` (https://github.com/ch-pat/google-hashcode): screen only: best program `hashcode-2022/main.py` totals 570,269, and none is first on an instance.
- `googleCodeHash_dasamantaraoaditya` (https://github.com/dasamantaraoaditya/googleCodeHash): not run: no program gave a valid output in our setup, and it stores no valid output.
- `google_hashcode_2022_Bhdzhdz` (https://github.com/Bhdzhdz/google_hashcode_2022): not run: does not build here. Its stored outputs score 1,199,089.
- `hascode_mmarouen` (https://github.com/mmarouen/hascode): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hash-code-2022_M3A-Team` (https://github.com/M3A-Team/hash-code-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hash-code-2022_hexmod` (https://github.com/hexmod/hash-code-2022): screen only: best program `src/main.py` totals 2,482,859, and none is first on an instance.
- `hash-code-2022_jcolladosp` (https://github.com/jcolladosp/hash-code-2022): screen only: best program `qualification_round/src/main.ts` totals 1,734, and none is first on an instance.
- `hashCode2022_Epado` (https://github.com/Epado/hashCode2022): screen only: best program `index.js` totals 2,322,254, and none is first on an instance.
- `hashCode2022_RideSVEL` (https://github.com/RideSVEL/hashCode2022): screen only: best program `main.py` totals 876,861, and none is first on an instance.
- `hashCode2022_Tom-stack3` (https://github.com/Tom-stack3/hashCode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hash_code_2022_nvog1` (https://github.com/nvog1/hash_code_2022): not run: does not build here, and it stores no valid output.
- `hashcode-2021_djefrey` (https://github.com/djefrey/hashcode-2021): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022-alambik_clementbegnaud` (https://github.com/clementbegnaud/hashcode-2022-alambik): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022-attempts_achingachris` (https://github.com/achingachris/hashcode-2022-attempts): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022-feb_VehpuS` (https://github.com/VehpuS/hashcode-2022-feb): screen only: best program `ordered_by_profit_ratio_with_roles_with_lvl_up/code.py` totals 1,937,201 (11 programs), and none is first on an instance.
- `hashcode-2022-gdgfi_fabian57fabian` (https://github.com/fabian57fabian/hashcode-2022-gdgfi): screen only: its program scored 0 or gave no valid output.
- `hashcode-2022-qualif_joffrey-bion` (https://github.com/joffrey-bion/hashcode-2022-qualif): not run: does not build here, and it stores no valid output.
- `hashcode-2022-qualification-round_HuzaifaIrfan-DSA` (https://github.com/HuzaifaIrfan-DSA/hashcode-2022-qualification-round): screen only: best program `bruteforce.py` totals 1,576,894, and none is first on an instance.
- `hashcode-2022-qualification_prague-pandas` (https://github.com/prague-pandas/hashcode-2022-qualification): screen only: best program `python/main.py` totals 2,641,302 (2 programs), and none is first on an instance.
- `hashcode-2022-qualification_schweikart` (https://github.com/schweikart/hashcode-2022-qualification): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022_HasinduLanka` (https://github.com/HasinduLanka/hashcode-2022): not run: no program gave a valid output in our setup. Its stored outputs score 1,701,655.
- `hashcode-2022_Knackie` (https://github.com/Knackie/hashcode-2022): not run: does not build here, and it stores no valid output.
- `hashcode-2022_MuhammedHasan` (https://github.com/MuhammedHasan/hashcode-2022): screen only: best program `src/main.py` totals 861,480, and none is first on an instance.
- `hashcode-2022_RobbeDP` (https://github.com/RobbeDP/hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022_SaffatHasan` (https://github.com/SaffatHasan/hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022_amanroy2001` (https://github.com/amanroy2001/hashcode-2022): screen only: best program `main.py` totals 2,089,652 (2 programs), and none is first on an instance.
- `hashcode-2022_ambolt314` (https://github.com/ambolt314/hashcode-2022): screen only: best program `crapgorithm.py` totals 1,958,636 (2 programs), and none is first on an instance.
- `hashcode-2022_antroseco` (https://github.com/antroseco/hashcode-2022): screen only: best program `main.py` totals 2,392,089, and none is first on an instance.
- `hashcode-2022_christianwiese` (https://github.com/christianwiese/hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022_florin141` (https://github.com/florin141/hashcode-2022): not run: does not build here, and it stores no valid output.
- `hashcode-2022_justsolomon` (https://github.com/justsolomon/hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022_krmbzds` (https://github.com/krmbzds/hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022_muety` (https://github.com/muety/hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-2022_onshimiye` (https://github.com/onshimiye/hashcode-2022): screen only: best program `solution.py` totals 1,816,049, and none is first on an instance.
- `hashcode-2022_orsa-scholis` (https://github.com/orsa-scholis/hashcode-2022): screen only: best program `src/main.rs` totals 972,242, and none is first on an instance.
- `hashcode-2022_tallosim` (https://github.com/tallosim/hashcode-2022): screen only: best program `notebook.ipynb` totals 110,421 (3 programs), and none is first on an instance.
- `hashcode-2022_theamankumarsingh` (https://github.com/theamankumarsingh/hashcode-2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode-qual-2022_AlexeyZhuravlev` (https://github.com/AlexeyZhuravlev/hashcode-qual-2022): screen only: best program `src/dima.cpp` totals 2,942,083 (2 programs), and none is first on an instance.
- `hashcode2022_Dabsunter` (https://github.com/Dabsunter/hashcode2022): screen only: best program `knowledge.py` totals 365,511, and none is first on an instance.
- `hashcode2022_Damzwan` (https://github.com/Damzwan/hashcode2022): screen only: best program `main.py` totals 1,879,652, and none is first on an instance.
- `hashcode2022_Dovgalyuk` (https://github.com/Dovgalyuk/hashcode2022): screen only: best program `main.cpp` totals 3,011,675 (2 programs), and none is first on an instance.
- `hashcode2022_IumoInfinium` (https://github.com/IumoInfinium/hashcode2022): screen only: its program scored 0 or gave no valid output.
- `hashcode2022_JDOsborne1` (https://github.com/JDOsborne1/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_Kitarsh` (https://github.com/Kitarsh/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_Phylu` (https://github.com/Phylu/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_albheim` (https://github.com/albheim/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_angelo-rendina-prima` (https://github.com/angelo-rendina-prima/hashcode2022): screen only: best program `src/main.rs` totals 2,605,095, and none is first on an instance.
- `hashcode2022_arberaga` (https://github.com/arberaga/hashcode2022): screen only: best program `src/main.java` totals 2,089,742, and none is first on an instance.
- `hashcode2022_arnodeceuninck` (https://github.com/arnodeceuninck/hashcode2022): screen only: best program `main.py` totals 2,394,327 (3 programs), and none is first on an instance.
- `hashcode2022_dzjkb` (https://github.com/dzjkb/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_englhardt` (https://github.com/englhardt/hashcode2022): not run: no program gave a valid output in our setup. Its stored outputs score 2,442,047.
- `hashcode2022_gleb-kov` (https://github.com/gleb-kov/hashcode2022): screen only: best program `solutions/e.cpp` totals 2,674,155 (5 programs), and none is first on an instance.
- `hashcode2022_gnitsua` (https://github.com/gnitsua/hashcode2022): screen only: best program `main.py` totals 1,853,654, and none is first on an instance.
- `hashcode2022_iamayushanand` (https://github.com/iamayushanand/hashcode2022): screen only: its program scored 0 or gave no valid output.
- `hashcode2022_idow09` (https://github.com/idow09/hashcode2022): screen only: best program `main.py` totals 25,771, and none is first on an instance.
- `hashcode2022_javgat` (https://github.com/javgat/hashcode2022): screen only: its program scored 0 or gave no valid output.
- `hashcode2022_jjustin` (https://github.com/jjustin/hashcode2022): screen only: best program `main.py` totals 538,744, and none is first on an instance.
- `hashcode2022_kanko-ghosh` (https://github.com/kanko-ghosh/hashcode2022): screen only: best program `hashcode.cpp` totals 1,855,166, and none is first on an instance.
- `hashcode2022_katie-hughes` (https://github.com/katie-hughes/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_kindermoumoute` (https://github.com/kindermoumoute/hashcode2022): not run: does not build here, and it stores no valid output.
- `hashcode2022_kirankuyate2157` (https://github.com/kirankuyate2157/hashcode2022): not run: no program gave a valid output in our setup. Its stored outputs score 1,663,984.
- `hashcode2022_kisel-dv` (https://github.com/kisel-dv/hashcode2022): screen only: best program `kisel-dv/12321.py` totals 2,164,843 (2 programs), and none is first on an instance.
- `hashcode2022_laurerunser` (https://github.com/laurerunser/hashcode2022): screen only: best program `src/Main.java` totals 1,454,859, and none is first on an instance.
- `hashcode2022_masterchief164` (https://github.com/masterchief164/hashcode2022): screen only: best program `code.cpp` totals 579,258, and none is first on an instance.
- `hashcode2022_micaelafonso` (https://github.com/micaelafonso/hashcode2022): screen only: best program `App.java` totals 1,777,783, and none is first on an instance.
- `hashcode2022_mullerpeter` (https://github.com/mullerpeter/hashcode2022): screen only: best program `main.py` totals 2,534,886, and none is first on an instance.
- `hashcode2022_n-sc` (https://github.com/n-sc/hashcode2022): screen only: best program `Problem/main_v2.cpp` totals 2,461,484 (3 programs), and none is first on an instance.
- `hashcode2022_noharms` (https://github.com/noharms/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_ogtayhuseynov0` (https://github.com/ogtayhuseynov0/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_ootks` (https://github.com/ootks/hashcode2022): not run: no program gave a valid output in our setup. Its stored outputs score 334,157.
- `hashcode2022_opiechow` (https://github.com/opiechow/hashcode2022): screen only: best program `team.py` totals 835,245, and none is first on an instance.
- `hashcode2022_otikev` (https://github.com/otikev/hashcode2022): screen only: best program `src/com/otikev/hashcode/Main.java` totals 1,587,330, and none is first on an instance.
- `hashcode2022_pblkt` (https://github.com/pblkt/hashcode2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode2022_sbrodehl` (https://github.com/sbrodehl/hashcode2022): screen only: best program `Qualification Round/main.py` totals 1,131,605, and none is first on an instance.
- `hashcode2022_tweedegolf` (https://github.com/tweedegolf/hashcode2022): screen only: best program `src/main.rs` totals 2,753,102, and none is first on an instance.
- `hashcode2022_wuttem` (https://github.com/wuttem/hashcode2022): screen only: best program `solve_mw.py` totals 446,803 (2 programs), and none is first on an instance.
- `hashcode2022_xoposhiy` (https://github.com/xoposhiy/hashcode2022): not run: no program gave a valid output in our setup. Its stored outputs score 3,050,544.
- `hashcode2022_yasardeniz9` (https://github.com/yasardeniz9/hashcode2022): not run: does not build here, and it stores no valid output.
- `hashcode22-EVREST_simbarras` (https://github.com/simbarras/hashcode22-EVREST): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode22_belmind` (https://github.com/belmind/hashcode22): screen only: best program `main.py` totals 1,711,500, and none is first on an instance.
- `hashcode_2022_Cthulhus-Knights` (https://github.com/Cthulhus-Knights/hashcode_2022): screen only: best program `index.js` totals 1,619,119, and none is first on an instance.
- `hashcode_2022_Mifour` (https://github.com/Mifour/hashcode_2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode_2022_Nicolaus93` (https://github.com/Nicolaus93/hashcode_2022): screen only: best program `src/solution.py` totals 2,602,617, and none is first on an instance.
- `hashcode_2022_StefPler` (https://github.com/StefPler/hashcode_2022): screen only: best program `projectDistributions.py` totals 227,232, and none is first on an instance.
- `hashcode_2022_davimatyi` (https://github.com/davimatyi/hashcode_2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode_2022_peirisabhi` (https://github.com/peirisabhi/hashcode_2022): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode_2022_qualification_miksax` (https://github.com/miksax/hashcode_2022_qualification): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode_22_tibovanheule` (https://github.com/tibovanheule/hashcode_22): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode_DjellalAbdou` (https://github.com/DjellalAbdou/hashcode): screen only: its program scored 0 or gave no valid output.
- `hashcode_Ruchit-rt` (https://github.com/Ruchit-rt/hashcode): screen only: its program scored 0 or gave no valid output.
- `hashcode_cyril-sabourault` (https://github.com/cyril-sabourault/hashcode): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode_floriandejonckheere` (https://github.com/floriandejonckheere/hashcode): not run: no program gave a valid output in our setup, and it stores no valid output.
- `hashcode_vikds` (https://github.com/vikds/hashcode): screen only: best program `2022/cpp/src/main.cpp` totals 880,053, and none is first on an instance.
- `icpc-hashcode2022_marianocrosetti` (https://github.com/marianocrosetti/icpc-hashcode2022): screen only: best program `solution_marian.cpp` totals 2,733,688 (9 programs), and none is first on an instance.
- `mentorship-and-teamwork_m-baj` (https://github.com/m-baj/mentorship-and-teamwork): screen only: no program scored above 0.
- `mentorship-teamwork-dataset_shefketbylykbashi` (https://github.com/shefketbylykbashi/mentorship-teamwork-dataset): not run: its solvers are the Nanored solvers with a time limit, which [instance_specific_greedy](solvers/instance_specific_greedy/) already covers.
- `qualification-round-2022_Gophing-Around` (https://github.com/Gophing-Around/qualification-round-2022): screen only: best program `main.go` totals 1,030,563, and none is first on an instance.
- `qualification_round_2022_HashCode-ICL-2022` (https://github.com/HashCode-ICL-2022/qualification_round_2022): screen only: best program `naive.py` totals 862,985, and none is first on an instance.
- `team-assignment-optimizer_giorgos1998` (https://github.com/giorgos1998/team-assignment-optimizer): not run: no program gave a valid output in our setup, and it stores no valid output.
- `AlexBlandin/Google-Hash` `2022/qualification-attempt-1/`: `main.py` is only a docstring (the rest of the folder is images and a problem write-up).
