#include "Mylib.h"
#include "Stud.h"
#include "Stud.cpp"

int main() {
    auto start = std::chrono::high_resolution_clock::now();


    vector<Studentas> stud;
    Studentas s;

    string eil;

    string ivedimo_skaitymo_p;
    cout << "Pasirinkite ar norite duomenis įvesti ar nuskaityti juos iš failo?(Įvesti - I, Nuskaityti - N) ";
    while(true){

        getline(cin, eil);   // Įvedama visą eilutė

        // Išimčių tvarkymas skirtas egzamino įvedimui.
        try{
            stringstream ss(eil);
            ss >> ivedimo_skaitymo_p;

            if(ivedimo_skaitymo_p != "N" && ivedimo_skaitymo_p != "n" && ivedimo_skaitymo_p != "I" && ivedimo_skaitymo_p != "i"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'I' arba 'N'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    int n;
    string random_pasirinkimas;

    ifstream failasIn;
    string f_pav;

    if(ivedimo_skaitymo_p == "N" || ivedimo_skaitymo_p == "n"){
        cout << "Įveskite failo pavadinimą: ";
        cin >> f_pav;

        failasIn.open(f_pav);

        if(failasIn.is_open()){
            string eil;
            getline(failasIn, eil);

            while(getline(failasIn, eil)){

                Stud_is_failo(s, eil);

                stud.push_back(s);
                valymas(s);
            }
            n = stud.size();
        }
        else{
            cout << "ERROR! FILE NOT FOUND!" << endl;
        }

        failasIn.close();
    }
    else if(ivedimo_skaitymo_p == "I" || ivedimo_skaitymo_p == "i"){
        cout << "Kiek studentų norite įtraukti į sistemą: ";
        while(true){
        getline(cin, eil);   // Įvedama visą eilutė

        // Išimčių tvarkymas skirtas egzamino įvedimui.
        try{
            stringstream ss(eil);
            if(!(ss >> n)){
                throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const invalid_argument &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        } 
        }

        for(int i = 0; i < n; i++){
        cout << "Įveskite studento vardą: ";
        cin >> s.vardas;

        cout << "Įveskite studento pavarde: ";
        cin >> s.pavarde;

        cout << "Ar norite, kad mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai?(Taip/Ne) ";
        cin >> random_pasirinkimas;

        if(random_pasirinkimas == "Taip" || random_pasirinkimas == "taip"){
            Duom_generavimas(s);
            stud.push_back(s);
            valymas(s);
        }
        else{

            // cin.ignore() pašalina visus likusius simbolius iš įvesties srauto iki pirmo naujos eilutės simbolio.
            cin.ignore(); 
            Duom_ivedimas(s);
            stud.push_back(s);
            valymas(s);
        }
    }
    }

    //Rusiavimas
    Studentu_rusiavimas(stud);

    string rez_pasirinkimas;
    cout << "Pasirinkite, kokį rezultatą norite matyti, įvertinimas pagal vidurkį įrašykite 'V', įvertinimas pagal medianą įrašykite 'M', įvertinimas pagal abu 'VM': ";
    cin >> rez_pasirinkimas;

    string isvedimo_pasirinkimas;
    cout << "Pasirinkite, kur rezultatą norite gauti, jei terminale įveskite 'T', jei faile įveskite 'F': ";
    cin >> isvedimo_pasirinkimas;
    
    SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Vykdymo laikas: " << duration.count() << " sekundžių" << std::endl;

    return 0;

}