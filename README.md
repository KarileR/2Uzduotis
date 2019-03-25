# 2Uzduotis

__Programos naudojimosi instrukcija__
- Pirmame lange išmetamas MENU, kuriame galima pasirinkti vieną iš trijų variantų:
- Pirma: Apdoroti duomenis iš tekstinio failo, kuriame Jūs surašote duomenis (/data/kursiokai.txt)
- Antra: Leisti kompiuteriui sugeneruoti atsitiktinį studentų sąrašą
- Trečia: Pasirinkti įvesti duomenis ranka programos veikimo metu
- Po kiekvieno pasirinkimo sekate nurodymus, ką reikia daryti toliau. Jei išmeta klaidą,  ji bus aprašyta, kodėl taip įvyko


# v1.0
__Pridėta:__
- Išmatuota programos veikimo sparta priklausomai nuo studentų dalijimo į dvi kategorijas strategijų

__Koreguota:__
- Pataisyta klaida, kai ir į vargšiukų ir kietiakų failą ismešdavo, kurie surinko 5.00 vidurkį.
- Nebeužlūžta prorgama esant 100000 studentų, naudojant deque konteinerį
- Pridėtas CMakeLists.txt failas (cmake)
- Pakeista studentų dalijimo strategija į 2. Atsižvelgiant į spartos analizę.

__Spartos analizė:__

__1 strategija:__

Bendro "student" konteinerio skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". 

| Studentų kiekis | std::vector <>  | std::list <> | std::deque <> |
| --- | --- | --- | --- |
| 10 |  1.142447 s    |  1.124414 s     |  1.129205 s    |
| 100 |  1.114925 s    |  1.128864 s     |  1.111133 s    |
| 1000 |  1.170952 s    |  1.197329 s     |  1.182502 s    |
| 10000 |  1.686749 s    |  1.490520 s     |  1.703526 s    |
| 100000 |  13.051815 s   |  3.442267 s     |  13.666179 s   |

__2 strategija:__

Bendro "student" konteinerio skaidymas panaudojant tik vieną naują konteinerį - "vargšiukai".

| Studentų kiekis | std::vector <>  | std::list <> | std::deque <> |
| --- | --- | --- | --- |
| 10 |  1.127436 s    |  1.097884 s    |  1.097234 s   |
| 100 |  1.187529 s    |   1.107106 s    |  1.111845 s   |
| 1000 | 1.196706 s   |  1.290120 s    |  1.180093 s    |
| 10000 |  1.611343 s   |  1.521588 s    |  1.489928 s    |
| 100000 |  4.045514 s   |  3.456682 s     |  4.381640 s   |

# v0.5
 
__Pridėta:__
- Ismatuotas konteineriu laikas

__Koreguota:__
- Pakeistas studentu rusiavimo procesas. Dabar rusiuojama i du atskirus vektorius ir jie isvedami atskirai i failus
- Pakeistas std::vector i std::list, del greitesnio programos veikimo
- Naudojant std::deque skaiciuojant 100 000 studentu programa uzlusta, bet skaiciuojant mazesnius veikia

__Spartos analize:__

| Studentų kiekis | std::vector <>  | std::list <> | std::deque <> |
| --- | --- | --- | --- |
| 10 |  1.140864 s    |  1.173359 s     |  1.144108 s    |
| 100 |  1.155565 s    |  1.183378 s     |  1.167640 s    |
| 1000 |  1.218738 s    |  1.217194 s     |  1.208246 s    |
| 10000 |  1.733005 s    |  1.497441 s     |  1.863636 s    |
| 100000 |  12.687928 s   |  3.573641 s     |  Error         |


 # v0.4

__Pridėta:__
- Ismatuotas konteineriu laikas
- Studentų sąrašų failų generavimas
- Studentų rūšiavimas į dvi grupes, kurių vienų galutinis balas < 5.0, o kitų >= 5.0 ir tų grupių išvedimas į atskirus failus
- Programos spartos analizė, keičiant generuojamo sąrašo dydį (GeneratedLists/All_times.txt)
- Studentai dviejuose naujuose isvestuose failuose surusiuoti pagal galutini vidurki mazejimo tvarka

__Koreguota:__
- Pilnai veikia visas Exception Handling, tiek skaitant iš failo, tiek įvedant duomenis ranka.
- Duomenu failas kursiokai.txt padarytas specialiai klaidingas, butent patikrinti, kaip programa veikia, kai ivedami ne reikiami duomenys

__Spartos analize:__

| Studentu kiekis | Programos laikas  | 
| --- | --- |
| 10 |  1.130982 s    |
| 100 |  1.210131  s    | 
| 1000 |  1.224044 s   |  
| 10000 |   1.640982 s    |  
| 100000 |  13.275929 s  | 
