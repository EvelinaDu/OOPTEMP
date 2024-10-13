#include "Mylib.h"
#include "Stud.h"
#include "timer.h"

int main() {
    vector<Studentas> stud;
    vector<Studentas> stud_Vargsiukai, stud_Kietiakai;
    Studentas s;
    vector<int> kiekis;         // Skirtas saugoti generuojamų failų dydžius

    string eil;         // Skirtas saugoti duomenu eilutei

    int n;                           // Skirtas išsaugoti studentų kiekį
    string random_pasirinkimas;      // Skirtas išsaugoti vartotojo pasirinkimą dėl įvertinimų generavimo.

    ifstream failasIn;               //Skirtas failo nuskaitymui
    string f_pav;                    //Failo pavadinimas

    string rez_pasirinkimas;
    string rusiavimo_p;
    string isvedimo_pasirinkimas;

    string ivedimo_skaitymo_p;
    cout << "Pasirinkite ar norite duomenis įvesti, nuskaityti juos iš failo, sugeneruoti ar testuoti duomenų failą?(Įvesti - I, Nuskaityti - N, Sugeneruoti - S, Testuoti - T) ";
    while(true){
        cin >> ivedimo_skaitymo_p;

        // Išimčių tvarkymas skirtas ivedimo ar skaitymo pasirinkimui.
        try{
            if(ivedimo_skaitymo_p != "N" && ivedimo_skaitymo_p != "n" && ivedimo_skaitymo_p != "I" && ivedimo_skaitymo_p != "i" && ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "s" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "t"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'I' arba 'N'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    if(ivedimo_skaitymo_p == "N" || ivedimo_skaitymo_p == "n"){
        Duom_is_failo(stud, s);
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
        }
    }

    if(random_pasirinkimas == "Taip" || random_pasirinkimas == "taip"){
        int nd_kiekis;
        cout << "Kiek namų darbų norėtumėt, kad būtų sugeneruota? ";
        cin.ignore();
        while(true){
        
            getline(cin, eil);   // Įvedama visą eilutė

            // Išimčių tvarkymas skirtas studentų skaičiaus įvedimui.
            try{
                stringstream ss(eil);
                if(!(ss >> nd_kiekis)){
                    throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
                }
                break;   // Išeiname iš while ciklo, jei įvestis teisinga.

            } catch (const invalid_argument &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
            } 
        }
        
        Duom_generavimas(s, cout, nd_kiekis);
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
    else if(ivedimo_skaitymo_p == "S" || ivedimo_skaitymo_p == "s"){
        kiekis = {1000, 10000, 100000, 1000000, 10000000};
        cout << endl;
        for (int k: kiekis){
            Timer t;

            Stud_failu_generavimas(stud, k);

            cout << "Failo su "<< stud.size() << " įrašų generavimo laikas: " << t.elapsed() << " s\n";
            stud.clear();
            cout << endl;
        }
    }
    else if(ivedimo_skaitymo_p == "T" || ivedimo_skaitymo_p == "t"){
        rez_pasirinkimas = pasirinkimas_del_galutinio();
        rusiavimo_p = pasirinkimas_del_rusiavimo();

        Duom_is_failo(stud, s);

        n = stud.size();
        Duom_tvarkymas(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas, rusiavimo_p, isvedimo_pasirinkimas, ivedimo_skaitymo_p, n);

    }

    if(ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "s" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "t"){
        rez_pasirinkimas = pasirinkimas_del_galutinio();
        rusiavimo_p = pasirinkimas_del_rusiavimo();
        isvedimo_pasirinkimas = pasirinkimas_isvedimo();
        n = stud.size();
        SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);

    }

    return 0;
}