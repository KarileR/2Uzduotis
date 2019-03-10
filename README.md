# 2Uzduotis

# v0.5
 

__Koreguota__
- Pakeistas studentu rusiavimo procesas. Dabar rusiuojama i du atskirus vektorius ir jie isvedami atskirai i failus
- Pakeistas std::vector i std::list, del greitesnio programos veikimo
- Naudojant std::deque skaiciuojant 100 000 studentu programa uzlusta, bet skaiciuojant mazesnius veikia

__Prideta__
- Ismatuotas konteineriu laikas

__Spartos analize__

| Konteineris | std::vector <>  | std::list <> | std::deque <> |
| --- | --- | --- | --- |
| 1 |  1.140864 s    |  1.173359 s     |  1.144108 s    |
| 2 |  1.155565 s    |  1.183378 s     |  1.167640 s    |
| 3 |  1.218738 s    |  1.217194 s     |  1.208246 s    |
| 4 |  1.733005 s    |  1.497441 s     |  1.863636 s    |
| 5 |  12.687928 s   |  3.573641 s     |  Error         |


 # v0.4

__Pridėta:__
- Ismatuotas konteineriu laikas
- Studentų sąrašų failų generavimas
- Studentų rūšiavimas į dvi grupes, kurių vienų galutinis balas < 5.0, o kitų >= 5.0 ir tų grupių išvedimas į atskirus failus
- Programos spartos analizė, keičiant generuojamo sąrašo dydį (GeneratedLists/All_times.txt)
- Studentai dviejuose naujuose isvestuose failuose surusiuoti pagal galutini vidurki mazejimo tvarka

__Koreguota__
- Pilnai veikia visas Exception Handling, tiek skaitant iš failo, tiek įvedant duomenis ranka.
- Duomenu failas kursiokai.txt padarytas specialiai klaidingas, butent patikrinti, kaip programa veikia, kai ivedami ne reikiami duomenys

__Analize__

| Studentu kiekis | Programos laikas  | 
| --- | --- |
| 10 |  1.130982 s    |
| 100 |  1.210131  s    | 
| 1000 |  1.224044 s   |  
| 10000 |   1.640982 s    |  
| 100000 |  13.275929 s  | 
