#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Studentas{
  string vardas, pavarde;
  vector <double> nd;
  double egz, galutinis_vid, galutinis_med;
};


void Duom_ivedimas(Studentas &s){
        string pasirinkimas;
        bool ivertinimo_ivedimas = false;


        cout << "Įveskite studento vardą: ";
        cin >> s.vardas;

        cout << "Įveskite studento pavarde: ";
        cin >> s.pavarde;


        cout << "Ar norite įvesti namų darbų įvertinimą? ";
        cin >> pasirinkimas;

        if (pasirinkimas == "Taip" || pasirinkimas == "taip"){
            ivertinimo_ivedimas = true;
        } else {
            ivertinimo_ivedimas = false;
        }

        int ivertinimas;
        int nd_nr = 1;
        while(ivertinimo_ivedimas){
            cout << nd_nr <<" Namų darbų" << " įvertinimas: ";
            nd_nr ++;
            cin >> ivertinimas;
            s.nd.push_back(ivertinimas);

            cout << "Ar norite įvesti namų darbų įvertinimą? ";
            cin >> pasirinkimas;

            if (pasirinkimas == "Taip" || pasirinkimas == "taip"){
                ivertinimo_ivedimas = true;
            } else {
                ivertinimo_ivedimas = false;
            }
        }

        cout << "Įveskite studento egzamino įvertinimą: ";
        cin >> s.egz;
}

int main() {
    vector<Studentas> stud;
    Studentas s;


}