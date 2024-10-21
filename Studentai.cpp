#include "Mylib.h"
#include "Stud.h"
#include "timer.h"


int main() {
    // vector<Studentas> stud;
    // vector<Studentas> stud_Vargsiukai, stud_Kietiakai;
    // Studentas s;
    // vector<int> kiekis;              // Skirtas saugoti generuojamų failų dydžius

    string eil;                      // Skirtas saugoti duomenu eilutei

    int n;                           // Skirtas išsaugoti studentų kiekį
    // string random_pasirinkimas;      // Skirtas išsaugoti vartotojo pasirinkimą dėl įvertinimų generavimo.

    ifstream failasIn;               //Skirtas failo nuskaitymui
    string f_pav;                    //Failo pavadinimas

    string rez_pasirinkimas;
    string rusiavimo_p;
    string isvedimo_pasirinkimas;


    string vektorius_arba_sarasas;
    cout << "Pasirinkite su kokia duomenų struktūra norite dirbti, su vektoriumi ar su sąrašu (V - vektorius, S - sąrašas): ";
    while(true){
        cin >> vektorius_arba_sarasas;

        // Išimčių tvarkymas skirtas vektoriaus arba sąrašo pasirinkimui.
        try{
            if(vektorius_arba_sarasas != "V" && vektorius_arba_sarasas != "v" && vektorius_arba_sarasas != "S" && vektorius_arba_sarasas != "s"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'V' arba 'S'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    string ivedimo_skaitymo_p = pasirinkimas_del_programos_vykdymo();

    if (vektorius_arba_sarasas == "V" || vektorius_arba_sarasas == "v"){
        vector<Studentas> stud;
        vector<Studentas> stud_Vargsiukai, stud_Kietiakai;
        Studentas s;
        vector<int> kiekis; 

        if(ivedimo_skaitymo_p == "N" || ivedimo_skaitymo_p == "n"){
            Duom_is_failo(stud, s);
        }
        else if(ivedimo_skaitymo_p == "I" || ivedimo_skaitymo_p == "i"){
            Info_ivedimas_ranka(stud, s, n);
        }    
        else if(ivedimo_skaitymo_p == "S" || ivedimo_skaitymo_p == "s"){
            kiekis = {1000, 10000, 100000, 1000000, 10000000};
            cout << endl;
            for (int k: kiekis){
                Timer t;

                Stud_failu_generavimas(k);

                cout << "Failo su "<< stud.size() << " įrašų generavimo laikas: " << t.elapsed() << " s.\n";
                stud.clear();
                cout << endl;
            }
        }
        else if(ivedimo_skaitymo_p == "T" || ivedimo_skaitymo_p == "t"){
            rez_pasirinkimas = pasirinkimas_del_galutinio();
            rusiavimo_p = pasirinkimas_del_rusiavimo();

            // system("dir /b *.txt");
            // system("dir *.txt /B");
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

    } 
    else{
        list<Studentas> stud;
        list<Studentas> stud_Vargsiukai, stud_Kietiakai;
        Studentas s;
        list<int> kiekis;

        if(ivedimo_skaitymo_p == "N" || ivedimo_skaitymo_p == "n"){
            Duom_is_failo(stud, s);
        }
        else if(ivedimo_skaitymo_p == "I" || ivedimo_skaitymo_p == "i"){
            Info_ivedimas_ranka(stud, s, n);
        }    
        else if(ivedimo_skaitymo_p == "S" || ivedimo_skaitymo_p == "s"){
            kiekis = {1000, 10000, 100000, 1000000, 10000000};
            cout << endl;
            for (int k: kiekis){
                Timer t;

                Stud_failu_generavimas(k);

                cout << "Failo su "<< k << " įrašų generavimo laikas: " << t.elapsed() << " s.\n";
                stud.clear();
                cout << endl;
            }
        }
        else if(ivedimo_skaitymo_p == "T" || ivedimo_skaitymo_p == "t"){
            rez_pasirinkimas = pasirinkimas_del_galutinio();
            rusiavimo_p = pasirinkimas_del_rusiavimo();

            // system("dir /b *.txt");
            // system("dir *.txt /B");
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
    }

    

    // if(ivedimo_skaitymo_p == "N" || ivedimo_skaitymo_p == "n"){
    //     Duom_is_failo(stud, s);
    // }
    // else if(ivedimo_skaitymo_p == "I" || ivedimo_skaitymo_p == "i"){
    //     Info_ivedimas_ranka(stud, s, n);
    // }    
    // else if(ivedimo_skaitymo_p == "S" || ivedimo_skaitymo_p == "s"){
    //     kiekis = {1000, 10000, 100000, 1000000, 10000000};
    //     cout << endl;
    //     for (int k: kiekis){
    //         Timer t;

    //         Stud_failu_generavimas(stud, s, k);

    //         cout << "Failo su "<< stud.size() << " įrašų generavimo laikas: " << t.elapsed() << " s.\n";
    //         stud.clear();
    //         cout << endl;
    //     }
    // }
    // else if(ivedimo_skaitymo_p == "T" || ivedimo_skaitymo_p == "t"){
    //     rez_pasirinkimas = pasirinkimas_del_galutinio();
    //     rusiavimo_p = pasirinkimas_del_rusiavimo();

    //     // system("dir /b *.txt");
    //     // system("dir *.txt /B");
    //     Duom_is_failo(stud, s);

    //     n = stud.size();
    //     Duom_tvarkymas(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas, rusiavimo_p, isvedimo_pasirinkimas, ivedimo_skaitymo_p, n);
    // }
    

    // if(ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "s" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "t"){
    //     rez_pasirinkimas = pasirinkimas_del_galutinio();
    //     rusiavimo_p = pasirinkimas_del_rusiavimo();
    //     isvedimo_pasirinkimas = pasirinkimas_isvedimo();
    //     n = stud.size();
    //     SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);

    // }

    return 0;
}