#include "Stud.h"
#include "timer.h"

// Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
void Duom_ivedimas(Studentas &s){

    cout << "Įveskite visus namų darbų įvertinimus. Norėdami baigti įvedimą spauskite dukart 'Enter' klavišą" << endl;
    string eil;        // Kintamasis įvesties eilutei saugoti
    int ivertinimas;

    // While ciklas, skirtas įrašyti studento namų darbų įvertinimus. Vyksta tol kol vartotojas nuspaudžia du kart "Enter".
    while(true){
        getline(cin, eil);   // Įvedama visą eilutė
        if(eil.empty()){     // Jei įvestis tuščia (buvo nuspaustas 'Enter'), nutraukiamas ciklas.  
            break;
        }

        // Išimčių tvarkymas skirtas namų darbų įvedimui.
        try{
            stringstream ss(eil);
            if(!(ss >> ivertinimas)){
                throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
            }

            if(ivertinimas < 1 || ivertinimas > 10){
                throw out_of_range("Netinkama įvestis, įvertinimas turi būti nuo 1 iki 10. ");
            }
            s.nd.push_back(ivertinimas);

        } catch (const invalid_argument &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą." << endl;
        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą." << endl;
        }
    }

    // Egzamino įvertinimo įvedimas.
    cout << "Įveskite studento egzamino įvertinimą: ";
    while(true){
        getline(cin, eil);   // Įvedama visą eilutė

        // Išimčių tvarkymas skirtas egzamino įvedimui.
        try{
            stringstream ss(eil);
            if(!(ss >> s.egz)){
                throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
            }

            if(s.egz < 1 || s.egz > 10){
                throw out_of_range("Netinkama įvestis, įvertinimas turi būti nuo 1 iki 10. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const invalid_argument &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

}

int min_rezult = 1;
int max_result = 10;

//Atsitiktiniu skaičiu generatorius
random_device rd_genrator;   
// Intervalas atsitiktinei reikšmei
uniform_int_distribution<int> Ivertinimas(min_rezult, max_result);

// Funkcija, kuri generuoja studento namų darbų ir egzamino įvertinimus.
void Duom_generavimas(Studentas &s, ostream &out ,int nd_kiekis){

    for(int i = 0; i < nd_kiekis; i++){

        int nd_ivertinimas = Ivertinimas(rd_genrator);
        out << setw(5) << left << nd_ivertinimas;
        s.nd.push_back(nd_ivertinimas);

    }

    s.egz = Ivertinimas(rd_genrator);
    out << s.egz << endl;
}


void Info_ivedimas_ranka(vector<Studentas>& stud, Studentas& s, int n){
    string eil;
    string random_pasirinkimas;

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

// Funkcija skirta nuskaityti studento įvertinimus iš failo.

template <typename Container>
void Duom_is_failo(Container &stud, Studentas &s){
    ifstream failasIn;   //Skirtas failo nuskaitymui
    string f_pav;        //Failo pavadinimas
    string eil;

    cout << "Įveskite failo pavadinimą: ";
    while(true){
        try{
            cin >> f_pav;

            Timer t;

            failasIn.open(f_pav);

            if (!failasIn.is_open()) {
                throw runtime_error("Klaida, failas nerastas! Bandykite dar kartą! ");
            }  
            
            // string eil;
            getline(failasIn, eil);

            while(getline(failasIn, eil)){
                stringstream ss(eil);
                ss >> s.vardas >> s.pavarde;

                int ivertinimas;
                string netinkantis_ivertinimas;
                while(true){
                    try{
                        if(!(ss >> ivertinimas)){
                            if(ss.eof()) break;   // eof - end of file
                            ss.clear();
                            ss >> netinkantis_ivertinimas;
                            throw invalid_argument("Netinkamas įvertinimas, įvertinimas nėra skaičius: '" + netinkantis_ivertinimas + "'");
                        }
                        if (ivertinimas < 1 || ivertinimas > 10){
                            throw out_of_range("Netinkamas įvertinimas: " + std::to_string(ivertinimas));
                        }
                        s.nd.push_back(ivertinimas);
                    } catch(const invalid_argument &e){
                        cout << "Klaida: " << e.what() << ". Šis įvertinimas bus praleistas." << endl;
                        continue;   //einame prie kito elemento
                    } catch(const out_of_range &e){
                        cout << "Klaida: " << e.what() << ". Šis įvertinimas bus praleistas." << endl;
                        continue;   //einame prie kito elemento
                    }               
                }

                if(!s.nd.empty()){
                    s.egz = s.nd.back();
                    s.nd.pop_back();
                }
                
                stud.push_back(s);
                valymas(s);
            }
            cout << endl;
            cout << "Failas sėkmingai perskaitytas. Studentų kiekis: " << stud.size() << endl; 
            cout << "Duomenų skaitymas užtruko: " << t.elapsed() << " s\n";
            
            break;   //Išeiname is while ciklo, jei failas atsidarė
        }catch (const runtime_error &e) {
            cout << e.what();
        }
    }

    failasIn.close();
}

template void Duom_is_failo<vector<Studentas>>(vector<Studentas>&, Studentas& s);
template void Duom_is_failo<list<Studentas>>(list<Studentas>&, Studentas& s);


// Funkcija skirta failo generavimui pagal įrašų kiekį
void Stud_failu_generavimas(vector<Studentas> &stud, Studentas &s, int kiekis){
    string pav = "Studentai_" + to_string(kiekis) + ".txt";

    ofstream failas;
    failas.open(pav);

    if(failas.is_open()){

        stud.resize(kiekis);

        // Antraštė
        failas << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde";
        for(int i = 0; i < 15; i++){
            failas << setw(5) << left << "ND" + to_string(i + 1);
        }
        failas << setw(5) << left << "EGZ" << endl;

        // Sukuriami studentų duomenys
        for(int i = 0; i < kiekis; i++){
            string vardas = "Vardas" + to_string(i + 1);
            string pavarde = "Pavarde" + to_string(i + 1);

            failas << setw(15) << left << vardas << setw(15) << left << pavarde  << " ";
            for(int i = 0; i < 15; i++){
                int nd_ivertinimas = Ivertinimas(rd_genrator);
                failas << setw(5) << left << nd_ivertinimas;
                s.nd.push_back(nd_ivertinimas);
            }
            s.egz = Ivertinimas(rd_genrator);
            failas << s.egz << endl;
        }
        

        failas.close();
        cout << "Failas "<< pav << " sugeneruotas sėkmingai! Sugeneruota: " << kiekis << " įrašai(-ų)" << endl;
        
    }
    else{
        cout << "ERROR! Nepavyko atidaryti " << pav << " failo" << endl;
    }

}


// Funkcija skirta galutiniam įvertinimui pagal vidurkį apskaičiuoti.
void Ivertinimas_vid(Studentas &s){
    double suma = 0;
    int nd_kiekis = s.nd.size();   // Gauname namų darbų kiekį.

    // Pridedame kiekievieną namų darbų įvertinimą prie bendros sumos.
    for (int j = 0; j < nd_kiekis; j++){
         suma += s.nd[j];
    }

    // Jei yra bent vienas namų darbas, skaičiuojame galutinį įvertinimą pagal vidurkį.
    if (nd_kiekis > 0 ){
        s.galutinis_vid = 0.4 * suma/nd_kiekis + 0.6 * s.egz;
    } else {
        s.galutinis_vid = 0.6 * s.egz;
    }


}

// Funkcija skirta galutiniam įvertinimui pagal medianą apskaičiuoti.
void Ivertinimas_med(Studentas &s){
    int nd_kiekis = s.nd.size();

    // Jei namų darbų nėra, tai galutinį įvertinimą nustatome pagal egzaminą.
    if (nd_kiekis == 0){
        s.galutinis_med = 0.6 * s.egz;
        return;
    }
    
    // Surušiuoname namų darbus
    sort(begin(s.nd), end(s.nd));


// Medianos ieškojimas
    double mediana = 0;
    int nr = nd_kiekis / 2;
    if (nd_kiekis % 2 == 0){
        mediana = (s.nd[nr - 1] + s.nd[nr]) / 2.0;
    } else {
        mediana = s.nd[nr];
    }

// Ivertinimo apskaičiavimas naudojant medianą.
    s.galutinis_med = 0.4 * mediana + 0.6 * s.egz;
    
}

// Funkcija, kuri skirta atspausdinti studento duomenis pagal vartotojo įvertinimo pasirinkimą (pagal vidurkį, medianą ar abu).
void Stud_spausdinimas(Studentas &s, ostream &out, string p){
    if(p == "V" || p == "v"){
        out << setw(15) << left << s.vardas << setw(16) << left << s.pavarde << setw(16) << left << fixed << setprecision(2) << s.galutinis_vid << endl;
    }
    else if(p == "M" || p == "m"){
        out << setw(15) << left << s.vardas << setw(16) << left << s.pavarde << setw(16) << left << fixed << setprecision(2) << s.galutinis_med << endl;
    }

}

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez_antraste(string pasirinkimas, ostream &out){
    
    if(pasirinkimas == "V" || pasirinkimas == "v"){
        out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
        out << "------------------------------------------------" << endl;
    }
    else if(pasirinkimas == "M" || pasirinkimas == "m"){
        out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
        out << "------------------------------------------------" << endl;
    }
}

// Funkcija skirta studentų vektoriui surušiuoti.
void Studentu_rusiavimas(vector<Studentas> &stud, string pasirinkimas, string galutinis_pasirinkimas){
    if(pasirinkimas == "VP" || pasirinkimas == "vp"){
        // Rūšiavimas pagal vardą ir pavardę
        sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
        if(s1.vardas != s2.vardas){
            return s1.vardas < s2.vardas;
        }
        return s1.pavarde < s2.pavarde;
        });
    } else if(pasirinkimas == "PV" || pasirinkimas == "PV"){
         // Rūšiavimas pagal pavardę ir vardą
        sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
        if(s1.pavarde != s2.pavarde){
            return s1.pavarde < s2.pavarde;
        }
        return s1.vardas < s2.vardas;
        });
    }
    else if(pasirinkimas == "GM" || pasirinkimas == "gm"){
        // Rušiavimas pagal galutinį įvertinimą
        if (galutinis_pasirinkimas == "V" || galutinis_pasirinkimas == "v"){
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
            return s1.galutinis_vid > s2.galutinis_vid;
        });
        } else if(galutinis_pasirinkimas == "M" || galutinis_pasirinkimas == "m"){
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
            return s1.galutinis_med > s2.galutinis_med;
        });
        }
    } else if(pasirinkimas == "GD" || pasirinkimas == "gd"){
        // Rušiavimas pagal galutinį įvertinimą
        if (galutinis_pasirinkimas == "V" || galutinis_pasirinkimas == "v"){
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
            return s1.galutinis_vid < s2.galutinis_vid;
        });
        } else if(galutinis_pasirinkimas == "M" || galutinis_pasirinkimas == "m"){
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
            return s1.galutinis_med < s2.galutinis_med;
        });
        }
    }
}

// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
void SpausdinimasRez(vector<Studentas> &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p){
    ofstream failasOut;

    for (int i = 0; i < n; i++){
        Ivertinimas_vid(stud[i]);
        Ivertinimas_med(stud[i]);

    }

    //Rusiavimas
    Studentu_rusiavimas(stud, rusiavimo_p, rez_pasirinkimas);

    if(isvedimo_pasirinkimas == "T" || isvedimo_pasirinkimas == "t"){
        Rez_antraste(rez_pasirinkimas, cout);
        for (int i = 0; i < n; i++){
        Stud_spausdinimas(stud.at(i), cout, rez_pasirinkimas);
        }
    }
    else if (isvedimo_pasirinkimas == "F" || isvedimo_pasirinkimas == "f" || ivedimo_skaitymo_p == "T" || ivedimo_skaitymo_p == "t"){
        failasOut.open("Rez.txt");

        if(failasOut.is_open()){

            Rez_antraste(rez_pasirinkimas, failasOut);
            for (int i = 0; i < n; i++){
                Stud_spausdinimas(stud.at(i), failasOut, rez_pasirinkimas);
            }

            failasOut.close();
            cout << "Rezultatas sėkmingai įrašytas į Rez.txt failą!" << endl;
        }
        else{
            cout << "ERROR! Nepavyko atidaryti Rez.txt failo" << endl;
        }
    }
}

// Funkcija, skirta išvalyti studento duomenis.
void valymas(Studentas &s){
    s.vardas.clear();
    s.pavarde.clear();
    s.nd.clear();
    s.egz = 0; 
}

// Funkcija, skirta sukurti du naujus vektorius vargšiukams ir kietiakams, taip studentai yra surūšiuojami į dvi grupes.
void Kategorijos_Priskirimas(vector<Studentas> &stud, vector<Studentas> &stud_Vargsiukai, vector<Studentas> &stud_Kietiakai, int n, string pasirinkimas){
    Studentas v, k;
    for (int i = 0; i < n; i++){
        if (pasirinkimas == "V" || pasirinkimas == "v"){
            if (stud[i].galutinis_vid < 5.0){
                v.vardas = stud[i].vardas;
                v.pavarde = stud[i].pavarde;
                v.galutinis_vid = stud[i].galutinis_vid;
                stud_Vargsiukai.push_back(v);
            }else{
                k.vardas = stud[i].vardas;
                k.pavarde = stud[i].pavarde;
                k.galutinis_vid = stud[i].galutinis_vid;
                stud_Kietiakai.push_back(k);
            }
        } else if (pasirinkimas == "M" || pasirinkimas == "m"){
            if (stud[i].galutinis_vid < 5.0){
                v.vardas = stud[i].vardas;
                v.pavarde = stud[i].pavarde;
                v.galutinis_med = stud[i].galutinis_med;
                stud_Vargsiukai.push_back(v);
            }
            else{
                k.vardas = stud[i].vardas;
                k.pavarde = stud[i].pavarde;
                k.galutinis_med = stud[i].galutinis_med;
                stud_Kietiakai.push_back(k);
            }
        }
    }
}

// Funkcija, įrašo į failą pateiktą vektorių.
void FailasPgalKategorija(vector<Studentas> &studentai, string pasirinkimas, string pav){
    ofstream failas;

    failas.open(pav);

    if (!failas.is_open()){
        cout << "Klaida atidarant failą. " << endl;
    }

    // Antraštė
    Rez_antraste(pasirinkimas, failas);

    for(auto &s : studentai){
        Stud_spausdinimas(s, failas, pasirinkimas);
    }

    failas.close();

    cout << "Rezultatas sėkmingai įrašytas į "<< pav <<" failą!" << endl;
}

string pasirinkimas_del_programos_vykdymo(){
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

    return ivedimo_skaitymo_p;
}

// Funkcija, skirta vartotojui pasirinkti galutinį įvertinimą, pagal vidurkį arba pagal medianą.
string pasirinkimas_del_galutinio(){
    string rez_pasirinkimas;
    cout << "Pasirinkite, kokį rezultatą norite matyti, įvertinimas pagal vidurkį įrašykite 'V', įvertinimas pagal medianą įrašykite 'M': ";

    while(true){ 
        cin >> rez_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas pasirinko norimą įvertinimą (V/M).
        try{

            if(rez_pasirinkimas != "V" && rez_pasirinkimas != "v" && rez_pasirinkimas != "M" && rez_pasirinkimas != "m"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'V' ir 'M'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }
    return rez_pasirinkimas;
}

// Funkcija, skirta vartotojui pasirinkti pagal ką reikia surūšiuoti studentus.
string pasirinkimas_del_rusiavimo(){

    string rusiavimo_p;
    cout << "Pasirinkite rūšiavimą, pagal vardą ir pavarde - 'VP', pagal pavardę ir vardą - 'PV', pagal galutinį įvertinimą mažėjančia tvarka - 'GM', pagal galutinį įvertinimą didėjančia tvarka - 'GD': ";
    
    while(true){ 
        cin >> rusiavimo_p;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas pasirinko norimą įvertinimą (VP/PV/GM/GD).
        try{

            if(rusiavimo_p != "VP" && rusiavimo_p != "vp" && rusiavimo_p != "PV" && rusiavimo_p != "pv" && rusiavimo_p != "GM" && rusiavimo_p != "gm" && rusiavimo_p != "GD" && rusiavimo_p != "gd" ){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'V', 'P', 'VP', 'GM' arba 'GD'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    return rusiavimo_p;
}

// Funkcija, skirta vartotojui pasirinkti kur nori matyti rezultatą, ar terminale, ar faile.
string pasirinkimas_isvedimo(){
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

    return isvedimo_pasirinkimas;
}

// Funkcija skirta duomenų tvarkymui, tai atspausdinimui, kategorijos priskirimui, naujų failų sukurimui.
void Duom_tvarkymas(vector<Studentas>& stud, vector<Studentas> &stud_Vargsiukai, vector<Studentas> &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kiekis){
        cout << endl;
        SpausdinimasRez(stud, kiekis, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);
        cout << endl;

        Timer t1;
        Kategorijos_Priskirimas(stud, stud_Vargsiukai, stud_Kietiakai, kiekis, rez_pasirinkimas);
        cout << "Failo iš "<< kiekis << " įrašų rūšiavimas į dvi grupes laikas: " << t1.elapsed() << " s.\n";
        cout << endl;

        Timer t2;
        // Studentai įrašyti i Vargsiukai.txt failą
        FailasPgalKategorija(stud_Vargsiukai, rez_pasirinkimas, "Vargsiukai.txt");
        cout << "Failo iš "<< kiekis << " įrašų vargšelių įrašymas į failą laikas: " << t2.elapsed() << " s.\n";
        cout << endl;

        Timer t3;
        // Studentai įrašyti i Kietiakai.txt failą
        FailasPgalKategorija(stud_Kietiakai, rez_pasirinkimas, "Kietiakai.txt");
        cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
        cout << endl;

}
