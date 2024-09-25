#include "Mylib.h"
#include "Stud.h"
#include "Stud.cpp"


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    vector<Studentas> stud;
    Studentas s;

    string ivedimo_skaitymo_p;
    cout << "Pasirinkite ar norite duomenis įvesti ar nuskaityti juos iš failo?(Įvesti - I, Nuskaityti - N)";
    cin >> ivedimo_skaitymo_p;

    int n;

    ifstream failas;
    string f_pav;

    if(ivedimo_skaitymo_p == "N"){
        cout << "Įveskite failo pavadinimą: ";
        cin >> f_pav;

        failas.open(f_pav);

        if(failas.is_open()){
            string eil;
            getline(failas, eil);

            while(getline(failas, eil)){

                Stud_is_failo(s, eil);

                stud.push_back(s);
                valymas(s);
            }
            n = stud.size();
        }
        else{
            cout << "ERROR! FILE NOT FOUND!" << endl;
        }

        failas.close();
    }
    else{
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
            cout << "Įveskite studento vardą: ";
            cin >> s.vardas;

            cout << "Įveskite studento pavarde: ";
            cin >> s.pavarde;
            // cin.ignore() pašalina visus likusius simbolius iš įvesties srauto iki pirmo naujos eilutės simbolio.
            cin.ignore(); 
            Duom_ivedimas(s);
            stud.push_back(s);
            valymas(s);
        }
    }
    }




    string rez_pasirinkimas;
    cout << "Pasirinkite, kokį rezultatą norite matyti, įvertinimas pagal vidurkį įrašykite 'V', įvertinimas pagal medianą įrašykite 'M', įvertinimas pagal abu 'VM': ";
    cin >> rez_pasirinkimas;

    Rez(rez_pasirinkimas);

    for (int i = 0; i < n; i++){
        Ivertinimas_vid(stud[i]);
        Ivertinimas_med(stud[i]);
        Spausdinimas(stud.at(i), rez_pasirinkimas);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Vykdymo laikas: " << duration.count() << " sekundžių" << std::endl;

    return 0;

}