# 2Uzduotis

__v0.5__
 
- Ismatuotas konteineriu laikas
- Pakeistas studentu rusiavimo procesas. Dabar rusiuojama i du atskirus vektorius ir jie isvedami atskirai i failus.
- Naudojant std::deque skaiciuojant 100 000 studentu programa uzlusta, bet skaiciuojant mazesnius veikia
- Pakeistas std::vector i std::list, del greitesnio programos veikimo

| Konteineris | std::vector <>  | std::list <> | std::deque <> |
| --- | --- | --- | --- |
| 1 |  1.140864 s    |  1.173359 s     |  1.144108 s    |
| 2 |  1.155565 s    |  1.183378 s     |  1.167640 s    |
| 3 |  1.218738 s    |  1.217194 s     |  1.208246 s    |
| 4 |  1.733005 s    |  1.497441 s     |  1.863636 s    |
| 5 |  12.687928 s   |  3.573641 s     |  Error         |

