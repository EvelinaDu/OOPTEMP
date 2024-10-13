# OOP

## Struktūra
### Struct Studentas
- `string vardas`: Studento vardas.
- `string pavarde`: Studento pavarde.
- `vector <double> nd`: Namų darbų įvertinimų vektorius.
- `double egz`: Egzamino įvertinimas
- `double galutinis_vid`: Galutinis įvertinimas pagal vidurkį
- `double galutinis_med`: Galutinis įvertinimas pagal medianą


## Aprašymas
Vartotojui suteikiamas pasirinkimas tarp duomenų įvedimo ranka, nuskaitymo iš failo, failų generavimo (generuojami 5 testiniai failai) ir failų testavimo. Vartotojui pasirinkus įvedima ranka, vartotojas privalo įvesti kiekį studentų, kuriuos nori įvesti į sistemą, taip pat privalo pateikti jų varbus bei pavardes, yra suteikiama galimybė namų darbų bei egzamino įvertinimus generuoti atsitiktinai dešimtbalėje sistemoe. Pagal vartotojo įvestus ar sugeneruotus duomenis yra apskaičiuojamas galutinis įvertinimas pagal vidurkį ir galutinis įvertinimas pagal medianą. Resultatai pateikiami pagal pasirinkimą arba terminale arba 'Rez.txt' faile. Vartotojui pasirinkus failo nuskaitymą, reikės suvesti failo pavadinimą ir bus atlikti tokie patys veiksmai kaip ir su įvedimu ranka. Vartotojui pasirinkus failų generavimą bus sugeneruoti 5 failai su įrašų kiekių: 1000, 10000, 100000, 1000000, 10000000. Vartotojui pasirinkus failų testavimą, pasirinkus ir įvedus norimo failo pavadinimą bus atliktie tokie veiksai: studentų rezultatai bus apskaičiuoti ir įrašyti į txt.failą, studentai rūšiuojami pagal vardą ir pavardę, pavardę ir vardą, galutionio įvertinimo mažėjimo arba didėjimo tvarka, studentai bus suskirstomi į dvi grupes pagal galutinį įvertinimą į 'vargškiukus'(galutinis balas < 5.0 ) ir 'kietiakus' (galutinis balas >= 5.0), sugrupuoti duomenis įrašomi į skirtingus failus.

## Programos vykdymo laikai:

# Failų generavimas:
Failas Studentai_1000.txt sugeneruotas sėkmingai! Sugeneruota: 1000 įrašai(-ų)
Failo su 1000 įrašų generavimo laikas: **0.0173236 s.**

Failas Studentai_10000.txt sugeneruotas sėkmingai! Sugeneruota: 10000 įrašai(-ų)
Failo su 10000 įrašų generavimo laikas: **0.119076 s.**

Failas Studentai_100000.txt sugeneruotas sėkmingai! Sugeneruota: 100000 įrašai(-ų)
Failo su 100000 įrašų generavimo laikas: **1.39498 s.**

Failas Studentai_1000000.txt sugeneruotas sėkmingai! Sugeneruota: 1000000 įrašai(-ų)
Failo su 1000000 įrašų generavimo laikas: **8.87131 s.**

Failas Studentai_10000000.txt sugeneruotas sėkmingai! Sugeneruota: 10000000 įrašai(-ų)
Failo su 10000000 įrašų generavimo laikas: **89.5782 s.**


# Programos veikimo greičio (spartos) analizė:
# 1000 įrašų
- Duomenų nuskaitymas iš failo: **0.008387 s.**
- Studentų rūšiavimas į dvi grupes/kategorijas: **0.000698 s.**
- Surūšiuotų studentų išvedimą į Vargšelių.txt failą: **0.005074 s.**
- Surūšiuotų studentų išvedimą į Kietiakus.txt failą: **0.004745 s.**

# 10000 įrašų
- Duomenų nuskaitymas iš failo: **0.328642 s.**
- Studentų rūšiavimas į dvi grupes/kategorijas: **0.010864 s.**
- Surūšiuotų studentų išvedimą į Vargšelių.txt failą: **0.030321 s.**
- Surūšiuotų studentų išvedimą į Kietiakus.txt failą: **0.037418 s.**

# 100000 įrašų
- Duomenų nuskaitymas iš failo: **0.922479 s.**
- Studentų rūšiavimas į dvi grupes/kategorijas: **0.024367 s.**
- Surūšiuotų studentų išvedimą į Vargšelių.txt failą: **0.198887 s.**
- Surūšiuotų studentų išvedimą į Kietiakus.txt failą: **0.288225 s.**

# 1000000 įrašų
- Duomenų nuskaitymas iš failo: **5.728837**
- Studentų rūšiavimas į dvi grupes/kategorijas: **0.21695**
- Surūšiuotų studentų išvedimą į Vargšelių.txt failą: **30.96127**
- Surūšiuotų studentų išvedimą į Kietiakus.txt failą: **2.541053**

# 10000000 įrašų
- Duomenų nuskaitymas iš failo: **53.09053**
- Studentų rūšiavimas į dvi grupes/kategorijas: **2.099277**
- Surūšiuotų studentų išvedimą į Vargšelių.txt failą: **154.318**
- Surūšiuotų studentų išvedimą į Kietiakus.txt failą: **30.06403**