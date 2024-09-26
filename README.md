# OOP

## Struktūra
### Struct Studentas
- `string vardas`: Studento vardas.
- `string pavarde`: Studento pavarde.
- `vector <double> nd`: Namų darbų įvertinimų vektorius.
- `double egz`: Egzamino įvertinimas
- `double galutinis_vid`: Galutinis įvertinimas pagal vidurkį
- `double galutinis_med`: Galutinis įvertinimas pagal medianą

## Vykdymo laikas
Kodo vykdymo laikas kartu su vartotojo įvedimu ir pasirinkimais (vartotojas rankiniu būdu įvedė du studentus ir po du įvertinimus): **26.56s** (priklauso nuo vartotojo įvedimui ir pasirinkimui skirto laiko).

## Aprašymas
- Vartotojas suteikiamas pasirinkimas ar duomenis nori suvesti ranka ar nuskaityti iš failo.
- Jei pasirenkamas skaitymas iš failo, tai vartotojui reiks tik pasirinkti kokį įvertinimo rezultatą nori matyti(Galutinis_vid, Galutinis_med, abu) ir reiks pasirinkti kur nori gauti rezultatą(T - terminalas, F - failas).
- Vartotojui pasirinkus įvedima ranka, vartotojas privalo įvesti kiekį studentų, kuriuos nori įvesti į sistemą;
- Taip pat privalo pateikti jų varbus bei pavardes;
- Vartotojas gali įvertinimų duomenis įvesti arba sugeneruoti atsitiktinai dešimtbalėje skačiavimo sistemoje;
- Pagal vartotojo įvestus ar sugeneruotus duomenis yra apskaičiuojamas galutinis įvertinimas pagal vidurkį ir galutinis įvertinimas pagal medianą.
- Vartotojui pasirinkus norima įvertinimo būdą yra atspausdinama lentelė su pateiktais įvertinimais(atspausdinama terminale arba įrašo į failą).


## Rūšiavimas
Funkcija skirta studentų vektoriui surušiuoti, rušiuojama pagal vardus, tačiau kai vardai sutampa, rušiuojama pagal pavardes.
void Studentu_rusiavimas(vector<Studentas> &stud){
    sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
        if(s1.vardas != s2.vardas){
            return s1.vardas < s2.vardas;
        }
        return s1.pavarde < s2.pavarde;
    });
}

## Vykdymo laikas
(įrašoma antraštė, apskaičiuojamas galutinis įvertinimas pagal vidurkį ir mediana, atspausdinamas studentu vektorius su rezultatais)

    auto start = std::chrono::high_resolution_clock::now();

    SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Vykdymo laikas: " << duration.count() << " sekundžių" << std::endl;

    return 0;

- studentai10000.txt ~  1.70175 s
- studentai100000.txt ~ 1.50289 s
- studentai1000000.txt ~ 12.8161 s