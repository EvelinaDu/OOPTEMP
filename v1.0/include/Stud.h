#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"

// Studento struktūra, kuri susideda iš vardo, pavardes, namų darbų vektoriaus, egzamino ir įvertinimų.
// struct Studentas{
//   string vardas, pavarde;
//   vector <double> nd;
//   double egz, galutinis_vid, galutinis_med;

// };

class Studentas{
  private: // duomenys
  string vardas_;
  string pavarde_;
  vector <double> nd_;
  double egz_;
  double galutinis_vid_;
  double galutinis_med_;

  public:
  // Konstrukteriai
  Studentas() : egz_(0), galutinis_vid_(0), galutinis_med_(0) { }

  Studentas(const string& vardas, const string& pavarde, const vector <double>& nd, double egz) : 
  vardas_(vardas), pavarde_(pavarde), nd_(nd), egz_(egz), galutinis_vid_(0), galutinis_med_(0) { }

  // Studentas(std::istream& is){
  //   readStudent(is);
  // }

  // set'eriai
  void setVardas(const string& vardas) {vardas_ = vardas; }
  void setPavarde(const string& pavarde) {pavarde_ = pavarde; }
  void setNd(const vector<double>& nd) {nd_ = nd; }
  void setEgz(const double& egz) {egz_ = egz; }
  void setGalutinis_vid(const double& ivertinimas){galutinis_vid_ = ivertinimas; }
  void setGalutinis_med(const double& ivertinimas){galutinis_med_ = ivertinimas; }

  // get'eriai
  inline string getVardas() const { return vardas_; }
  inline string getPavarde() const { return pavarde_; }
  inline double getEgz() const {return egz_; }
  inline vector<double> getNd() const { return nd_; }
  inline double getGalutinis_vid() const { return galutinis_vid_; }
  inline double getGalutinis_med() const { return galutinis_med_; }
  


  // void pridetiIvertinima(double ivertinimas){ nd_.push_back(ivertinimas); }

  
  void Ivertinimas_vid();
  void Ivertinimas_med();


  // ~Studentas() = default;
  ~Studentas(){};
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
void Duom_is_failo(Container &stud);

// Funkcija skirta failo generavimui pagal įrašų kiekį.
void Stud_failu_generavimas(int kiekis);

// // Funkcija skirta galutiniam įvertinimui pagal vidurkį apskaičiuoti.
// void Ivertinimas_vid(Studentas &s);

// // Funkcija skirta galutiniam įvertinimui pagal medianą apskaičiuoti.
// void Ivertinimas_med(Studentas &s);

// Funkcija, kuri skirta atspausdinti studento duomenis pagal vartotojo įvertinimo pasirinkimą (pagal vidurkį, medianą).
void Stud_spausdinimas(Studentas &s, ostream &out, string p, string isvedimo_pasirinkimas);

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez_antraste(string pasirinkimas, ostream &out, string isvedimo_pasirinkimas);

// Funkcija skirta studentų rūšiavimui.
template <typename Container>
void Studentu_rusiavimas(Container &stud, string pasirinkimas, string galutinis_pasirinkimas);

// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
template <typename Container>
void SpausdinimasRez(Container &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p);

// Funkcija, skirta išvalyti studento duomenis.
void valymas(Studentas &s);

// Funkcija, skirta sukurti du naujus kontainerius vargšiukams ir kietiakams, taip studentai yra surūšiuojami į dvi grupes.
template <typename Container>
void Kategorijos_Priskirimas1(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas);

// Funkcija, kuri surūšiuoja studentus į dvi grupes, jei studento įvertinimas < 5.0, priskiriamas "Vargšiukų" kontaineriui
// ir studentas ištrinamas iš bendro. Taip bendrame liks tik tie studentai, kurių įvertinimas >= 5.0.
template <typename Container>
void Kategorijos_Priskirimas2(Container &stud, Container &stud_Vargsiukai, string pasirinkimas);

// Funkcija, kuri surūšiuoja studentus į dvi grupes, jei vartotojo pasirinkta duomenų struktūra yra vektorius, tai rūšiuojama pagal pirmą strategiją,
// jei duomenų struktūra - sąrašas, tai rūšiuojama pagal 2 strategiją.
template <typename Container>
void Kategorijos_Priskirimas3(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas);

// Funkcija, kuri įrašo į failą pateiktą kontainerį.
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

// Funkcija, skirta vartotojui pasirinkti pagal kurią strategiją norimą skirstyti studentus į dvi grupes (1, 2, 3).
int pasirinkimas_del_strategijos();

// Funkcija skirta duomenų tvarkymui, tai rezultatų įrašymui, kategorijos priskirimui, naujų failų sukūrimui.
template <typename Container>
void Duom_tvarkymas(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);

#endif