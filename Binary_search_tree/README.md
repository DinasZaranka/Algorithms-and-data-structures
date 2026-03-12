# 1 laboratorinis darbas – Binary Search Tree ADT

Šiame darbe realizuotas Abstract Data Type - Binary Search Tree, C kalboje.

Medis realizuotas naudojant dinaminę atmintį (rodykles). 
Kiekviena medžio šaka saugo jos šaknies reikšmę, bei rodykles į kairį ir dešinį pomedžius. 
BST pagrindinė savybė:
- visi elementai kairėje yra mažesni uz šaknį, o dešinėje – didesni.


### Programos funkcijos:
- `create()` – sukuria tuščią medį.
- `done()` – sunaikina medį ir atlaisvina atmintį.
- `count()` – grąžina elementų skaičių.
- `isEmpty()` – patikrina ar medis tuščias.
- `isFull()` – grąžina false (naudojama dinaminė atmintis).
- `toString()` – išveda medžio elementus didėjimo tvarka.
- `insert()` – įterpia naują elementą išlaikant BST savybę.
- `clone()` – sukuria gilią medžio kopiją.
- `makeEmpty()` – išvalo medį.
- `balance()` – subalansuoja medį naudojant inorder rekonstrukcijos metodą.

### Kompiliavimas:
Projektas kompiliuojamas kompiuterio terminale ivedus `make`

Windows aplinkoje galima kompiliuoti atidarius GO.cmd
- Tokiu atveju GO.cmd reikia įvesti savo kompiuterio USERDOMAIN.
- GO.cmd pritaikytas kad veiktu MIF kompiuteryje\


labas **dinai** reikia kompiuteri UZRAKINTI
pone zagune, parasykite dinui 2