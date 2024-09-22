#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include <algorithm> 

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

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

void Ivertinimas_vid(Studentas &s){
    double suma = 0;
    int nd_kiekis = s.nd.size();

// Ivertinimo apskaiciavimas naudojant vidurki
    for (int j = 0; j < nd_kiekis; j++){
         suma += s.nd[j];
    }

    if (nd_kiekis > 0){
        s.galutinis_vid = 0.4 * suma/nd_kiekis + 0.6 * s.egz;
    } else {
        s.galutinis_vid = 0.6 * s.egz;
    }


}

void Ivertinimas_med(Studentas &s){
    int nd_kiekis = s.nd.size();

    if (nd_kiekis == 0){
        s.galutinis_med = 0.6 * s.egz;
        return;
    }
    
    sort(begin(s.nd), end(s.nd));


// Medianos ieskojimas
    double mediana = 0;
    int nr = nd_kiekis / 2;
    if (nd_kiekis % 2 == 0){
        mediana = (s.nd[nr - 1] + s.nd[nr]) / 2.0;
    } else {
        mediana = s.nd[nr];
    }

// Ivertinimo apskaiciavimas naudojant mediana
    s.galutinis_med = 0.4 * mediana + 0.6 * s.egz;
    
}

void Spausdinimas(Studentas &s){
    cout << s.vardas << "         " << s.pavarde << "       " << fixed << setprecision(2) << s.galutinis_vid << "             " << s.galutinis_med << endl;
}

void valymas(Studentas &s){
    s.vardas.clear();
    s.pavarde.clear();
    s.nd.clear();
    s.egz = 0; 
}

int main() {
    vector<Studentas> stud;
    Studentas s;

    int n;
    cout << "Kiek studentų norite įtraukti į sistemą: ";
    cin >> n;

    for(int i = 0; i < n; i++){

        string random_pasirinkimas;
        cout << "Ar norite, kad mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai?(Taip/Ne) ";
        cin >> random_pasirinkimas;

        if(random_pasirinkimas == "Taip" || random_pasirinkimas == "taip"){
            Duom_generavimas(s);
            stud.push_back(s);
            valymas(s);
        }
        else{
            Duom_ivedimas(s);
            stud.push_back(s);
            valymas(s);
        }
    }

    cout << "Vardas" << "        " << "Pavarde" << "        " << "Galutinis (Vid.)" << "/ " << "Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++){
        Ivertinimas_vid(stud[i]);
        Ivertinimas_med(stud[i]);
        Spausdinimas(stud.at(i));
    }

}