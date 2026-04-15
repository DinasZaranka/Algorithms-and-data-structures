# 2 Labaratorinis darbas. Turime N darbų, kurių atlikimo trukmė t1, t2,..tN­, kurių baigimo terminai d1, d2,..dN. Jei darbai neatliekami laiku, bauda atitinkamai b1, b2,..bN. Kokia eilės tvarka atlikti darbus, kad bauda būtų minimali.

### Bendroji kompetencija. Bendravimas ir bendradarbiavimas
- Atliekant šį darbą buvo bendradarbiaujama aptariant galimus algoritmo realizavimo būdus ir programos struktūrą.
- Diskusijų metu buvo lyginami skirtingi sprendimo metodai (pilnas perrinkimas, Branch and Bound, heuristikos).
- Aptariamos galimos optimizacijos bei klaidų taisymo strategijos.

### Sprendimo metodas
Uždavinys sprendžiamas naudojant Branch and Bound algoritmą.

Algoritmas generuoja galimas darbų atlikimo tvarkas ir skaičiuoja sukauptą baudos kainą. Jei dalinis sprendimas jau turi didesnę baudą nei geriausias rastas sprendimas, tokia šaka yra atmetama.

Paieška realizuota naudojant LIFO strategiją su Stack duomenų struktūra.

### Kompiliavimas:
Projektas kompiliuojamas kompiuterio terminale ivedus `make`

Windows aplinkoje galima kompiliuoti atidarius GO.cmd
- Tokiu atveju GO.cmd reikia įvesti savo kompiuterio USERDOMAIN.
- GO.cmd pritaikytas kad veiktu MIF kompiuteryje\

### Programos paleidimas
Windows aplinkoje programa galima paleisti atidarius GO.cmd
Programa paleidžiama iš komandinės eilutės įvedus:

`./main.exe [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number] [-timeout milisekundės]`
Parametrai:
- failo_vardas – įvesties failas su darbų duomenimis (- reiškia standartinį įvedimo srautą)
- -mode – paieškos režimas
- -timeout – maksimalus programos vykdymo laikas milisekundėmis

## Testai
Pagal [Codecrucks - Job sequencing using branch and bound](https://codecrucks.com/job-sequencing-using-branch-and-bound/)
Pagal [Youtube - Job Sequencing with Deadline - Branch and Bound](https://www.youtube.com/watch?v=M7Fl_z7_J2k)

Testas1: t={2, 1, 2, 1}, d={3, 1,
6, 4}, b={100, 10, 15, 27}.

Testas2: t={1, 1, 1}, d={1, 2,
3}, b={3, 2, 7}. 

Testas3: t={1,
1, 1}, d={3, 3, 2}, b={0, 0, 10}.

Testas4: t={2, 1, 3, 2}, d={1, 1,
5, 2}, b={3, 1, 2, 2}.

