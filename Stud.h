#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"

// Studento struktūra, kuri susideda iš vardo, pavardes, namų darbų vektoriaus, egzamino ir įvertinimu.
struct Studentas{
  string vardas, pavarde;
  vector <double> nd;
  double egz, galutinis_vid, galutinis_med;

};

struct Laikas{
  double failo_generavimas;
  double failo_nuskaitymas;
  double stud_rusiavimas;
  double stud_isvedimas_k;
  double stud_isvedimas_v;
};

// Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
void Duom_ivedimas(Studentas &s);

// Funkcija, kuri generuoja studento namų darbų ir egzamino įvertinimus.
void Duom_generavimas(Studentas &s, ostream &out, int nd_kiekis);

// Funkcija skirta nuskaityti studento įvertinimus iš failo.
void Stud_is_failo(Studentas &s, string eil);

void Stud_failu_generavimas(vector<Studentas> &stud, int kiekis);

// Funkcija skirta galutiniam įvertinimui pagal vidurkį apskaičiuoti.
void Ivertinimas_vid(Studentas &s);

// Funkcija skirta galutiniam įvertinimui pagal medianą apskaičiuoti.
void Ivertinimas_med(Studentas &s);

// Funkcija, kuri skirta atspausdinti studento duomenis pagal vartotojo įvertinimo pasirinkimą (pagal vidurkį, medianą ar abu).
void Stud_spausdinimas(Studentas &s, ostream &out, string p);

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez_antraste(string pasirinkimas, ostream &out);

// Funkcija skirta studentų vektoriui surušiuoti, rušiuojama pagal vardus, tačiau kai vardai sutampa, rušiuojama pagal pavardes.
void Studentu_rusiavimas(vector<Studentas> &stud, string pasirinkimas, string galutinis_pasirinkimas);

// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
void SpausdinimasRez(vector<Studentas> &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p);

// Funkcija, skirta išvalyti studento duomenis.
void valymas(Studentas &s);

void Failo_Generavimas_Nuskaitymas(vector<Studentas> &stud, Studentas &s, vector<Laikas> &Funkciju_Laikas, int laiko_vnt, int irasu_kiekis);

void Kategorijos_Priskirimas(vector<Studentas> &stud, vector<Studentas> &stud_Vargsiukai, vector<Studentas> &stud_Kietiakai, int n, string pasirinkimas);

void FailasPgalKategorija(vector<Studentas> studentai, string pasirinkimas, string pav);

string pasirinkimas_del_galutinio();

string pasirinkimas_del_rusiavimo();

string pasirinkimas_isvedimo();

void Duom_tvarkymas(vector<Studentas> &stud, vector<Studentas> &stud_Vargsiukai, vector<Studentas> &stud_Kietiakai, vector<Laikas> &Funkciju_Laikas, int laiko_vnt, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kiekis);

#endif