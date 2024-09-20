#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()


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

void Duom_generavimas(Studentas &s){
    cout << "Įveskite studento vardą: ";
    cin >> s.vardas;

    cout << "Įveskite studento pavarde: ";
    cin >> s.pavarde;

    int nd_kiekis;
    cout << "Kiek namų darbų norėtumėt, kad būtų sugeneruota? ";
    cin >> nd_kiekis;

    int nd_nr = 1;
    srand(time(0));

    for(int i = 0; i < nd_kiekis; i++){

        int nd_ivertinimas = rand() % 10 + 1;

        cout << nd_nr <<" Namų darbų" << " įvertinimas: " << nd_ivertinimas << endl;
        s.nd.push_back(nd_ivertinimas);
        nd_nr ++;

    }

    s.egz = rand() % 10 + 1;
    cout << "Egzamino įvertinimas: " << s.egz << endl;
}

int main() {
    vector<Studentas> stud;
    Studentas s;


}