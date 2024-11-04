#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"

// Studento struktūra, kuri susideda iš vardo, pavardes, namų darbų vektoriaus, egzamino ir įvertinimu.
struct Studentas{
  string vardas, pavarde;
  vector <double> nd;
  double egz, galutinis_vid, galutinis_med;

};

// Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
void Duom_ivedimas(Studentas &s);

// Funkcija, kuri generuoja studento namų darbų ir egzamino įvertinimus.
void Duom_generavimas(Studentas &s, ostream &out, int nd_kiekis);

// Funkcija, kurioje klausiama kiek studentų vartotojas norėtų įtraukti, klausiama studentų vardų bei pavardžių, 
// klausiama koks įvertinimų įvedimas(rankinis ar generavimas) ir pagal tai įvykdoma. 
template <typename Container>
void Info_ivedimas_ranka(Container &stud, Studentas &s, int n);

// Funkcija skirta nuskaityti studento įvertinimus iš failo.
template <typename Container>
void Duom_is_failo(Container &stud, Studentas &s);

// Funkcija skirta studentų failo generavimui.
void Stud_failu_generavimas(int kiekis);

// Funkcija skirta galutiniam įvertinimui pagal vidurkį apskaičiuoti.
void Ivertinimas_vid(Studentas &s);

// Funkcija skirta galutiniam įvertinimui pagal medianą apskaičiuoti.
void Ivertinimas_med(Studentas &s);

// Funkcija, kuri skirta atspausdinti studento duomenis pagal vartotojo įvertinimo pasirinkimą (pagal vidurkį, medianą ar abu).
void Stud_spausdinimas(Studentas &s, ostream &out, string p, string isvedimo_pasirinkimas);

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez_antraste(string pasirinkimas, ostream &out, string isvedimo_pasirinkimas);

// Funkcija skirta studentų vektoriui surušiuoti, rušiuojama pagal vardus, tačiau kai vardai sutampa, rušiuojama pagal pavardes.
template <typename Container>
void Studentu_rusiavimas(Container &stud, string pasirinkimas, string galutinis_pasirinkimas);

// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
template <typename Container>
void SpausdinimasRez(Container &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p);

// Funkcija, skirta išvalyti studento duomenis.
void valymas(Studentas &s);

// Funkcija, skirta sukurti du naujus vektorius vargšiukams ir kietiakams, taip studentai yra surūšiuojami į dvi grupes.
template <typename Container>
void Kategorijos_Priskirimas1(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas);

template <typename Container>
void Kategorijos_Priskirimas2(Container &stud, Container &stud_Vargsiukai, string pasirinkimas);

template <typename Container>
void Kategorijos_Priskirimas3(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas);

// Funkcija, įrašo į failą pateiktą vektorių.
template <typename Container>
void FailasPgalKategorija(Container &studentai, string pasirinkimas, string isvedimo_pasirinkimas, string pav);

// Funkcija, skirta vartotojui pasirinkti programos vykdymą (Įvesti - I, Nuskaityti - N, Sugeneruoti - S, Testuoti - T).
string pasirinkimas_del_programos_vykdymo();

// Funkcija, skirta vartotojui pasirinkti duomenų struktūrą (V - vektorius, S - sąrašas).
string pasirinkimas_del_duom_strukturos();

// Funkcija, skirta vartotojui pasirinkti galutinį įvertinimą, pagal vidurkį arba pagal medianą.
string pasirinkimas_del_galutinio();

// Funkcija, skirta vartotojui pasirinkti pagal ką reikia surūšiuoti studentus.
string pasirinkimas_del_rusiavimo();

// Funkcija, skirta vartotojui pasirinkti kur nori matyti rezultatą, ar terminale, ar faile.
string pasirinkimas_isvedimo();

// Funkcija, suteikianti galimybę vartotojui pasirinkti norimą strategiją.
int pasirinkimas_del_kategorijos();

// Funkcija skirta duomenų tvarkymui, tai rezultatų įrašymui, kategorijos priskirimui, naujų failų sukūrimui.
template <typename Container>
void Duom_tvarkymas(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);

#endif