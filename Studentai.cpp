#include "Mylib.h"
#include "Stud.h"

int main() {
    auto start = std::chrono::high_resolution_clock::now();


    vector<Studentas> stud;
    Studentas s;
    string eil;   // Skirtas saugoti duomenu eilutei

    string ivedimo_skaitymo_p;
    cout << "Pasirinkite ar norite duomenis įvesti ar nuskaityti juos iš failo?(Įvesti - I, Nuskaityti - N) ";
    while(true){
        cin >> ivedimo_skaitymo_p;

        // Išimčių tvarkymas skirtas ivedimo ar skaitymo pasirinkimui.
        try{
            if(ivedimo_skaitymo_p != "N" && ivedimo_skaitymo_p != "n" && ivedimo_skaitymo_p != "I" && ivedimo_skaitymo_p != "i"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'I' arba 'N'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    int n;   // Skirtas išsaugoti studentų kiekį
    string random_pasirinkimas;   // Skirtas išsaugoti vartotojo pasirinkimą dėl įvertinimų generavimo.

    ifstream failasIn;   //Skirtas failo nuskaitymui
    string f_pav;        //Failo pavadinimas

    if(ivedimo_skaitymo_p == "N" || ivedimo_skaitymo_p == "n"){
        cout << "Įveskite failo pavadinimą: ";
        while(true){
            try{
                cin >> f_pav;

                failasIn.open(f_pav);

                if (!failasIn.is_open()) {
                    throw runtime_error("Klaida, failas nerastas! Bandykite dar kartą! ");
                }  
            
                string eil;
                getline(failasIn, eil);

                while(getline(failasIn, eil)){
                    Stud_is_failo(s, eil);
                    stud.push_back(s);
                    valymas(s);
                }
                n = stud.size();
                cout << "Failas sėkmingai perskaitytas. Studentų kiekis: " << n << endl; 
                break;   //Išeiname is while ciklo, jei failas atsidarė
            }catch (const runtime_error &e) {
                cout << e.what();
            }
        }
        failasIn.close();
    }
    else if(ivedimo_skaitymo_p == "I" || ivedimo_skaitymo_p == "i"){
        cout << "Kiek studentų norite įtraukti į sistemą: ";
        cin.ignore();
        while(true){
            
            getline(cin, eil);   // Įvedama visą eilutė.
            // Išimčių tvarkymas skirtas studentų skaičiaus įvedimui.
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
        while(true){

            cin >> random_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas tikrai įvedė 'taip' arba 'ne'.
            try{

                if(random_pasirinkimas != "Taip" && random_pasirinkimas != "taip" && random_pasirinkimas != "Ne" && random_pasirinkimas != "ne"){
                    throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'Taip' arba 'Ne'. ");
                }
                break;   // Išeiname iš while ciklo, jei įvestis teisinga.

            } catch (const out_of_range &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
            }
        }


        if(random_pasirinkimas == "Taip" || random_pasirinkimas == "taip"){
            Duom_generavimas(s);
            stud.push_back(s);
            valymas(s);
        }
        else if(random_pasirinkimas == "Ne" || random_pasirinkimas == "ne"){

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

    while(true){ 
        cin >> rez_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas pasirinko norimą įvertinimą (V/M/VM).
        try{

            if(rez_pasirinkimas != "V" && rez_pasirinkimas != "v" && rez_pasirinkimas != "M" && rez_pasirinkimas != "m" && rez_pasirinkimas != "VM" && rez_pasirinkimas != "vm" ){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'V', 'M' arba 'VM'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
        }

    string isvedimo_pasirinkimas;
    cout << "Pasirinkite, kur norėtumėte gauti rezultatą, jei terminale įveskite 'T', jei faile įveskite 'F': ";

    while(true){
        cin >> isvedimo_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas teisingai pasirinko, kur bus pateiktas rezultatas (T/F).
        try{

            if(isvedimo_pasirinkimas != "T" && isvedimo_pasirinkimas != "t" && isvedimo_pasirinkimas != "F" && isvedimo_pasirinkimas != "f"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'T' arba 'F'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }

    }

    // auto start = std::chrono::high_resolution_clock::now();

    SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Vykdymo laikas: " << duration.count() << " sekundžių" << std::endl;

    return 0;

}