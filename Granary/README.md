# 3 Labaratorinis darbas. Grūdų sandėlis

### Panaudoti ADT:
- **Eilė** (queue) - Paimta iš dėstytojo puslapio (1gusa1802). Klaidų rasta: 0.
- **Stekas** (stack) - Paimta iš dėstytojo puslapio (1kast1133). Klaidų rasta: 0.
Defektų nerasta.

### Varianto sąlyga:
11. **Grūdų sandėlis** (ADT: stekas, eilė). Įmonė aktyviai prekiauja grūdais. Kiekvieną dieną įmonė perka ir sandėliuoja grūdus bei juos parduoda (atsitiktinai nuo 0 iki 100% sandėlyje turimų grūdų). Yra nustatyta per dieną superkamų grūdų norma (pvz., 100 t) ir supirkimo kaina (pvz., 200 LT/t), bet natūralu, kad ne visomis dienomis vienodai sekasi, todėl ekspertiškai žinomas superkamų grūdų kiekio maksimalus nuokrypis (pvz., 15%, tai reiškia, kad kiekvieną dieną įmonė superka 85-115 t grūdų) ir maksimalus grūdų supirkimo kainos nuokrypis (pvz., 5%, tai reiškia, kad įmonė superka gūdus po 190-210 LT/t). Parduodama grūdus įmonė ima nustatytą antkainį (pvz., 10%) nuo apskaitinės grūdų kainos. Gali būti naudojami tokie atsargų apskaitos metodai: 1) FIFO supirkimo: pirmiausia parduodami seniausiai įsigyti grūdai, apskaitinė grūdų kaina lygi supirkimo kainai; 2) LIFO svertinių vidurkių: pirmiausia parduodami šviežiausi grūdai; apskaitinė gautų grūdų kaina nustatoma kaip tuo metu sandėlyje turimų grūdų kainų svertinis vidurkis (pvz., jei sandėlyje turėjome 200 t grūdų, kurių apskaitinė kaina 95 LT/t ir įsigijome dar 100 t po 110 LT/t, tai įsigytų grūdų apskaitinė kaina yra 100 LT/t = (200 * 95 + 100 * 110) / (200 + 100)). Tikslas: patyrinėti, kurį grūdų apskaitos metodą naudodama įmonė gauna didesnį pelną.


### Bendroji kompetencija. **Bendravimas ir bendradarbiavimas**
- Atliekant šį darbą buvo bendradarbiaujama aptariant galimus algoritmo realizavimo būdus ir programos struktūrą.
- Diskusijų metu buvo lyginami skirtingi sprendimo metodai (pilnas perrinkimas, Branch and Bound, heuristikos).
- Aptariamos galimos optimizacijos bei klaidų taisymo strategijos.

### Kompiliavimas:
Projektas kompiliuojamas kompiuterio terminale įvedus `make`

Windows aplinkoje galima kompiliuoti atidarius GO.cmd
- Tokiu atveju GO.cmd reikia įvesti savo kompiuterio USERDOMAIN
- GO.cmd pritaikytas kad veiktu MIF kompiuteryje\

### Programos paleidimas
Windows aplinkoje programa galima paleisti atidarius GO.cmd
Programa paleidžiama iš komandinės eilutės įvedus:

`./granary.exe [-\failo_vardas] [-rnd testo_numeris]`

Parametrai:
-failo_vardas – įvesties failas su darbų duomenimis. (Jeigu failas nenurodomas naudojamas atitinkamas .cfg failas)
-rnd - pseudo-atsitiktinio skaičiaus davikliaus reikšmė
