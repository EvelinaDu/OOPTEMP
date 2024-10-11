#include "Mylib.h"
#include "Stud.h"

int main() {
    vector<Studentas> stud;
    vector<Studentas> stud_Vargsiukai, stud_Kietiakai;
    Studentas s;
    vector<int> kiekis;
    vector<Laikas> Funkciju_Laikas(5);
    // Laikas L;
    string eil;   // Skirtas saugoti duomenu eilutei

    string rez_pasirinkimas;
    string rusiavimo_p;
    string isvedimo_pasirinkimas;

    string ivedimo_skaitymo_p;
    cout << "Pasirinkite ar norite duomenis įvesti, nuskaityti juos iš failo ar sugeneruoti ir nuskaityti juos iš failo?(Įvesti - I, Nuskaityti - N, Sugeneruoti ir Nuskaityti - SN) ";
    while(true){
        cin >> ivedimo_skaitymo_p;

        // Išimčių tvarkymas skirtas ivedimo ar skaitymo pasirinkimui.
        try{
            if(ivedimo_skaitymo_p != "N" && ivedimo_skaitymo_p != "n" && ivedimo_skaitymo_p != "I" && ivedimo_skaitymo_p != "i" && ivedimo_skaitymo_p != "SN" && ivedimo_skaitymo_p != "sn"){
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
            
                // string eil;
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
            int nd_kiekis;
            string eil;
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
    }
    } 
    else if(ivedimo_skaitymo_p == "SN" || ivedimo_skaitymo_p == "sn"){
        int laiko_vnt = 0;
        rez_pasirinkimas = pasirinkimas_del_galutinio();
        rusiavimo_p = pasirinkimas_del_rusiavimo();

        kiekis = {1000, 10000, 100000};
        for (int k: kiekis){
            cout << endl;
            Failo_Generavimas_Nuskaitymas(stud, s, Funkciju_Laikas, laiko_vnt, k);
            Duom_tvarkymas(stud, stud_Vargsiukai, stud_Kietiakai, Funkciju_Laikas, laiko_vnt, rez_pasirinkimas, rusiavimo_p, isvedimo_pasirinkimas, ivedimo_skaitymo_p, k);
            laiko_vnt++;
        }
    }

    if(ivedimo_skaitymo_p != "SN" && ivedimo_skaitymo_p != "sn"){
        rez_pasirinkimas = pasirinkimas_del_galutinio();
        rusiavimo_p = pasirinkimas_del_rusiavimo();
        isvedimo_pasirinkimas = pasirinkimas_isvedimo();
        SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);

    }

    if(ivedimo_skaitymo_p == "SN" || ivedimo_skaitymo_p == "sn"){
        cout << endl;
        cout << "-----------------------Operacijų vykdymo laikai---------------------------" << endl;
        for(int i = 0; i < kiekis.size(); i++){
            int n = kiekis[i];
            cout << endl;
            cout << "Failas iš " << n << " įrašų, generavimo laikas: " << Funkciju_Laikas[i].failo_generavimas  << " sekundžių" << endl;
            cout << "Failas iš " << n << " įrašų, nuskaitymo laikas: " << Funkciju_Laikas[i].failo_nuskaitymas << " sekundžių" << endl;
            cout << "Failas iš " << n << " įrašų, rūšiavimas į dvi grupes laikas: " << Funkciju_Laikas[i].stud_rusiavimas << " sekundžių" << endl;
            cout << "Failas iš " << n << " įrašų, vargšelių įrašymas į failą likas: " << Funkciju_Laikas[i].stud_isvedimas_k << " sekundžių" << endl;
            cout << "Failas iš " << n << " įrašų, kietiakų įrašymas į failą laikas: " << Funkciju_Laikas[i].stud_isvedimas_v << " sekundžių" << endl;
            cout << "Bendras funkcijų veikimo laikas: " << Funkciju_Laikas[i].failo_generavimas + Funkciju_Laikas[i].failo_nuskaitymas + Funkciju_Laikas[i].stud_rusiavimas + Funkciju_Laikas[i].stud_isvedimas_k + Funkciju_Laikas[i].stud_isvedimas_v << "sekundžių" << endl;
        }
        // return 1;
    }
    return 0;

}