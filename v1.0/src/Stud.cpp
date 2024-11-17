
#include "../include/Stud.h"
#include "../include/timer.h"

// Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
void Duom_ivedimas(Studentas &s){

    cout << "Įveskite visus namų darbų įvertinimus. Norėdami baigti įvedimą spauskite dukart 'Enter' klavišą" << endl;
    string eil;             // Kintamasis įvesties eilutei saugoti
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

            s.pridetiIvertinima(ivertinimas);
            // s.setNd.push_back(ivertinimas);
            // s.nd.push_back(ivertinimas);

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
            if(!(ss >> ivertinimas)){
                throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
            }

            if(ivertinimas < 1 || ivertinimas > 10){
                throw out_of_range("Netinkama įvestis, įvertinimas turi būti nuo 1 iki 10. ");
            }
            s.setEgz(ivertinimas);
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
        s.pridetiIvertinima(nd_ivertinimas);
        // s.nd.push_back(nd_ivertinimas);

    }
    double egzoIvertinimas;
    egzoIvertinimas = Ivertinimas(rd_genrator);
    // s.egz = Ivertinimas(rd_genrator);
    s.setEgz(egzoIvertinimas);
    out << egzoIvertinimas << endl;
    // out << s.egz << endl;
}

// Funkcija, kurioje klausiama kiek studentų vartotojas norėtų įtraukti, klausiama studentų vardų bei pavardžių, 
// klausiama koks įvertinimų įvedimas(rankinis ar generavimas) ir pagal tai įvykdoma. 
template <typename Container>
void Info_ivedimas_ranka(Container &stud, Studentas &s, int n){
    string eil;
    string random_pasirinkimas;
    string vardas;
    string pavarde;

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
        cin >> vardas;
        s.setVardas(vardas);

        cout << "Įveskite studento pavarde: ";
        cin >> pavarde;
        s.setPavarde(pavarde);

        cout << "Ar norite, kad mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai?(Taip/Ne) ";
        while(true){

            cin >> random_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas tikrai įvedė 'taip' arba 'ne'.
            try{

                if(random_pasirinkimas != "Taip" && random_pasirinkimas != "taip" && random_pasirinkimas != "TAIP" && random_pasirinkimas != "Ne" && random_pasirinkimas != "ne"&& random_pasirinkimas != "Ne"){
                    throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'Taip' arba 'Ne'. ");
                }
                break;   // Išeiname iš while ciklo, jei įvestis teisinga.

            } catch (const out_of_range &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
            }
        }

        if(random_pasirinkimas == "Taip" || random_pasirinkimas == "taip" || random_pasirinkimas == "TAIP"){
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
        else if(random_pasirinkimas == "Ne" || random_pasirinkimas == "ne" || random_pasirinkimas == "NE"){

            // cin.ignore() pašalina visus likusius simbolius iš įvesties srauto iki pirmo naujos eilutės simbolio.
            cin.ignore(); 
            Duom_ivedimas(s);
            stud.push_back(s);
            valymas(s);
        }

    } 
}

template void Info_ivedimas_ranka<vector<Studentas>>(vector<Studentas>&, Studentas&, int);
template void Info_ivedimas_ranka<list<Studentas>>(list<Studentas>&, Studentas&, int);


// Funkcija skirta nuskaityti studento įvertinimus iš failo.
template <typename Container>
void Duom_is_failo(Container &stud, Studentas &s){
    ifstream failasIn;   //Skirtas failo nuskaitymui
    string f_pav;        //Failo pavadinimas
    string eil;
    string vardas, pavarde;

    cout << "Įveskite failo pavadinimą: ";
    while(true){
        try{
            cin >> f_pav;

            Timer t;

            failasIn.open(f_pav);

            if (!failasIn.is_open()) {
                throw runtime_error("Klaida, failas nerastas! Bandykite dar kartą! ");
            }  
            
            getline(failasIn, eil);

            while(getline(failasIn, eil)){
                stringstream ss(eil);
                ss >> vardas >> pavarde;
                s.setVardas(vardas);
                s.setPavarde(pavarde);

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
                        s.pridetiIvertinima(ivertinimas);
                        // s.nd.push_back(ivertinimas);
                    } catch(const invalid_argument &e){
                        cout << "Klaida: " << e.what() << ". Šis įvertinimas bus praleistas." << endl;
                        continue;   //einame prie kito elemento
                    } catch(const out_of_range &e){
                        cout << "Klaida: " << e.what() << ". Šis įvertinimas bus praleistas." << endl;
                        continue;   //einame prie kito elemento
                    }               
                }

                // if(!s.nd.empty()){
                //     s.egz = s.nd.back();
                //     s.nd.pop_back();
                // }

                if(!s.getNd().empty()){
                    s.setEgz(s.getNd().back());
                    s.getNd().pop_back();
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


// Funkcija skirta failo generavimui pagal įrašų kiekį.
void Stud_failu_generavimas(int kiekis){
    string pav = "Studentai_" + to_string(kiekis) + ".txt";

    ofstream failas;
    failas.open(pav);

    if(failas.is_open()){

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
            }
            int egz = Ivertinimas(rd_genrator);
            failas << setw(5) << left << egz << "\n";
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
    // int nd_kiekis = s.nd.size();   // Gauname namų darbų kiekį.
    int nd_kiekis = s.getNd().size();

    // Pridedame kiekievieną namų darbų įvertinimą prie bendros sumos.
    for (int j = 0; j < nd_kiekis; j++){
        //  suma += s.nd[j];
         suma += s.getNd()[j];
    }

    double ivertinimas;
    // Jei yra bent vienas namų darbas, skaičiuojame galutinį įvertinimą pagal vidurkį.
    if (nd_kiekis > 0 ){
        // s.galutinis_vid = 0.4 * suma/nd_kiekis + 0.6 * s.egz;
        ivertinimas = 0.4 * suma/nd_kiekis + 0.6 * s.getEgz();
        s.setGalutinis_vid(ivertinimas);
    } else {
        // s.galutinis_vid = 0.6 * s.egz;
        ivertinimas =  0.6 * s.getEgz();
        s.setGalutinis_vid(ivertinimas);
    }


}

// Funkcija skirta galutiniam įvertinimui pagal medianą apskaičiuoti.
void Ivertinimas_med(Studentas &s){
    // int nd_kiekis = s.nd.size();
    int nd_kiekis = s.getNd().size();

    // Jei namų darbų nėra, tai galutinį įvertinimą nustatome pagal egzaminą.
    if (nd_kiekis == 0){
        s.setGalutinis_med(0.6 * s.getEgz());
        // s.galutinis_med = 0.6 * s.egz;
        return;
    }
    
    // Surušiuoname namų darbus
    // sort(begin(s.nd), end(s.nd));
    sort(begin(s.getNd()), end(s.getNd()));


// Medianos ieškojimas
    double mediana = 0;
    int nr = nd_kiekis / 2;
    if (nd_kiekis % 2 == 0){
        // mediana = (s.nd[nr - 1] + s.nd[nr]) / 2.0;
        mediana = (s.getNd()[nr - 1] + s.getNd()[nr]) / 2.0;
    } else {
        // mediana = s.nd[nr];
        mediana = s.getNd()[nr];
    }

// Ivertinimo apskaičiavimas naudojant medianą.
    // s.galutinis_med = 0.4 * mediana + 0.6 * s.egz;
    s.setGalutinis_med( 0.4 * mediana + 0.6 * s.getEgz());
    
}

// Funkcija, kuri skirta atspausdinti studento duomenis pagal vartotojo įvertinimo pasirinkimą (pagal vidurkį, medianą).
void Stud_spausdinimas(Studentas &s, ostream &out, string p, string isvedimo_pasirinkimas){
    string vardas, pavarde;
    vardas = s.getVardas();
    pavarde = s.getPavarde();
    double galutinis;
    if(isvedimo_pasirinkimas  == "T" || isvedimo_pasirinkimas == "t"){
        if(p == "V" || p == "v"){
            galutinis = s.getGalutinis_vid();
            out << setw(15) << left << vardas << setw(16) << left << pavarde << setw(20) << left << fixed << setprecision(2) << galutinis  << setw(20) << left << &s << endl;
        }
        else if(p == "M" || p == "m"){
            galutinis = s.getGalutinis_med();
            out << setw(15) << left << vardas << setw(16) << left << pavarde << setw(20) << left << fixed << setprecision(2) << galutinis  << setw(20) << left << &s << endl;
        }
    } else{
        if(p == "V" || p == "v"){
            galutinis = s.getGalutinis_vid();
            out << setw(15) << left << vardas << setw(16) << left << pavarde << setw(16) << left << fixed << setprecision(2) << galutinis << endl;
        }
        else if(p == "M" || p == "m"){
            galutinis = s.getGalutinis_med();
            out << setw(15) << left << vardas << setw(16) << left << pavarde << setw(16) << left << fixed << setprecision(2) << galutinis << endl;
        }
    }
    

}

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez_antraste(string pasirinkimas, ostream &out, string isvedimo_pasirinkimas){
    
    if (isvedimo_pasirinkimas == "T" || isvedimo_pasirinkimas == "t"){
        if(pasirinkimas == "V" || pasirinkimas == "v"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Adresas atmintyje" << endl;
            out << "-------------------------------------------------------------------------" << endl;
        }
        else if(pasirinkimas == "M" || pasirinkimas == "m"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << left << "Galutinis (Med.)" << setw(20) << left << "Adresas atmintyje" << endl;
            out << "-------------------------------------------------------------------------" << endl;
        }
    } else {
        if(pasirinkimas == "V" || pasirinkimas == "v"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
            out << "------------------------------------------------" << endl;
        }
        else if(pasirinkimas == "M" || pasirinkimas == "m"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
            out << "------------------------------------------------" << endl;
        }
    }
    

}

// Funkcija skirta studentų rūšiavimui.
template <typename Container>
void Studentu_rusiavimas(Container &stud, string pasirinkimas, string galutinis_pasirinkimas){
    if constexpr (is_same_v<Container, vector<Studentas>>){
        if(pasirinkimas == "VP" || pasirinkimas == "vp" || pasirinkimas == "Vp" || pasirinkimas == "vP"){
        // Rūšiavimas pagal vardą ir pavardę
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
            if(s1.getVardas() != s2.getVardas()){
                return s1.getVardas() < s2.getVardas();
            }
            return s1.getPavarde() < s2.getPavarde();
            });
        } else if(pasirinkimas == "PV" || pasirinkimas == "pv" || pasirinkimas == "Pv" || pasirinkimas == "pV"){
            // Rūšiavimas pagal pavardę ir vardą
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
            if(s1.getPavarde() != s2.getPavarde()){
                return s1.getPavarde() < s2.getPavarde();
            }
            return s1.getVardas() < s2.getVardas();
            });
        }
        else if(pasirinkimas == "GM" || pasirinkimas == "gm" || pasirinkimas == "Gm" || pasirinkimas == "gM"){
            // Rušiavimas pagal galutinį įvertinimą mažėjančiai
            if (galutinis_pasirinkimas == "V" || galutinis_pasirinkimas == "v"){
                sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
                return s1.getGalutinis_vid() > s2.getGalutinis_vid();
            });
            } else if(galutinis_pasirinkimas == "M" || galutinis_pasirinkimas == "m"){
                sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
                return s1.getGalutinis_med() > s2.getGalutinis_med();
            });
            }
        } else if(pasirinkimas == "GD" || pasirinkimas == "gd" || pasirinkimas == "Gd" || pasirinkimas == "gD"){
            // Rušiavimas pagal galutinį įvertinimą didėjančiai
            if (galutinis_pasirinkimas == "V" || galutinis_pasirinkimas == "v"){
                sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
                return s1.getGalutinis_vid() < s2.getGalutinis_vid();
            });
            } else if(galutinis_pasirinkimas == "M" || galutinis_pasirinkimas == "m"){
                sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
                return s1.getGalutinis_med() < s2.getGalutinis_med();
            });
            }
        }
    } else {
        if(pasirinkimas == "VP" || pasirinkimas == "vp" || pasirinkimas == "Vp" || pasirinkimas == "vP"){
            // Rūšiavimas pagal vardą ir pavardę
            stud.sort([](const Studentas &s1, const Studentas &s2) {
                if (s1.getVardas() != s2.getVardas()) {
                    return s1.getVardas() < s2.getVardas();
                }
                return s1.getPavarde() < s2.getPavarde();
            });
        } else if(pasirinkimas == "PV" || pasirinkimas == "pv" || pasirinkimas == "Pv" || pasirinkimas == "pV"){
            // Rūšiavimas pagal pavardę ir vardą
            stud.sort([](const Studentas &s1, const Studentas &s2) {
                if (s1.getPavarde() != s2.getPavarde()) {
                    return s1.getPavarde() < s2.getPavarde();
                }
                return s1.getVardas() < s2.getVardas();
            });
        } else if(pasirinkimas == "GM" || pasirinkimas == "gm" || pasirinkimas == "Gm" || pasirinkimas == "gM"){
            // Rušiavimas pagal galutinį įvertinimą mažėjančiai
            if (galutinis_pasirinkimas == "V" || galutinis_pasirinkimas == "v"){
                stud.sort([](const Studentas &s1, const Studentas &s2) {
                    return s1.getGalutinis_vid() > s2.getGalutinis_vid();
                });
            } else if(galutinis_pasirinkimas == "M" || galutinis_pasirinkimas == "m"){
                stud.sort([](const Studentas &s1, const Studentas &s2){
                    return s1.getGalutinis_med() > s2.getGalutinis_med();
                });
            }
        } else if(pasirinkimas == "GD" || pasirinkimas == "gd" || pasirinkimas == "Gd" || pasirinkimas == "gD"){
            // Rušiavimas pagal galutinį įvertinimą didėjančiai
            if (galutinis_pasirinkimas == "V" || galutinis_pasirinkimas == "v"){
                stud.sort([](const Studentas &s1, const Studentas &s2) {
                    return s1.getGalutinis_vid() < s2.getGalutinis_vid();
                });
            } else if(galutinis_pasirinkimas == "M" || galutinis_pasirinkimas == "m"){
                stud.sort([](const Studentas &s1, const Studentas &s2){
                    return s1.getGalutinis_med() < s2.getGalutinis_med();
                });
            }
        }
    }
}


// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
template <typename Container>
void SpausdinimasRez(Container &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p){
    ofstream failasOut;

    // Kiekvienam studentui apskaičiuojamas įvertinimas pagal vidurkį ir medianą
    auto i = stud.begin();          // i - iteratorius, nurodantis į pirmąjį studentą
    while(i != stud.end()){
        Ivertinimas_vid(*i);        // *i - studentas, į kuri rodo iteratorius
        Ivertinimas_med(*i);
        ++i;
    }

    //Rusiavimas
    Studentu_rusiavimas(stud, rusiavimo_p, rez_pasirinkimas);

    if(isvedimo_pasirinkimas == "T" || isvedimo_pasirinkimas == "t"){
        Rez_antraste(rez_pasirinkimas, cout, isvedimo_pasirinkimas);

        for (auto &studentas : stud){
            Stud_spausdinimas(studentas, cout, rez_pasirinkimas, isvedimo_pasirinkimas);
        }

    }
    else if (isvedimo_pasirinkimas == "F" || isvedimo_pasirinkimas == "f" || ivedimo_skaitymo_p == "T" || ivedimo_skaitymo_p == "t"){
        failasOut.open("Rez.txt");

        if(failasOut.is_open()){

            Rez_antraste(rez_pasirinkimas, failasOut, isvedimo_pasirinkimas);

            for (auto &studentas : stud){
            Stud_spausdinimas(studentas, failasOut, rez_pasirinkimas, isvedimo_pasirinkimas);
            }

            failasOut.close();
            cout << "Rezultatas sėkmingai įrašytas į Rez.txt failą!" << endl;
        }
        else{
            cout << "ERROR! Nepavyko atidaryti Rez.txt failo" << endl;
        }
    }
}

template void SpausdinimasRez<vector<Studentas>>(vector<Studentas>&, int, string, string, string, string);
template void SpausdinimasRez<list<Studentas>>(list<Studentas>&, int, string, string, string, string);


// Funkcija, skirta išvalyti studento duomenis.
void valymas(Studentas &s){
    // s.vardas.clear();
    // s.pavarde.clear();
    // s.nd.clear();
    // s.egz = 0; 
}

// Funkcija, skirta sukurti du naujus kontainerius vargšiukams ir kietiakams, taip studentai yra surūšiuojami į dvi grupes.
template <typename Container>
void Kategorijos_Priskirimas1(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas){
    for (const auto& studentas : stud){
        if (pasirinkimas == "V" || pasirinkimas == "v"){
            if (studentas.getGalutinis_vid() < 5.0){
                stud_Vargsiukai.push_back(studentas);
            } else {
                stud_Kietiakai.push_back(studentas);
            }
        } 
        else if(pasirinkimas == "M" || pasirinkimas == "m"){
            if (studentas.getGalutinis_med() < 5.0){
                stud_Vargsiukai.push_back(studentas);
            } else {
                stud_Kietiakai.push_back(studentas);
            }
        }
    }
}

// Funkcija, kuri surūšiuoja studentus į dvi grupes, jei studento įvertinimas < 5.0, priskiriamas "Vargšiukų" kontaineriui
// ir studentas ištrinamas iš bendro. Taip bendrame liks tik tie studentai, kurių įvertinimas >= 5.0.
template <typename Container>
void Kategorijos_Priskirimas2(Container &stud, Container &stud_Vargsiukai, string pasirinkimas){

    if constexpr (is_same_v<Container, vector<Studentas>>){
        if (pasirinkimas == "V" || pasirinkimas == "v"){
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
            return s1.galutinis_vid > s2.galutinis_vid;
            });
        } else if(pasirinkimas == "M" || pasirinkimas == "m"){
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
            return s1.galutinis_med > s2.galutinis_med;
            });
        }
    }      
    else if (is_same_v<Container, list<Studentas>>){
        if (pasirinkimas == "V" || pasirinkimas == "v"){
                stud.sort([](const Studentas &s1, const Studentas &s2) {
                    return s1.galutinis_vid > s2.galutinis_vid;
                });
        } else if(pasirinkimas == "M" || pasirinkimas == "m"){
            stud.sort([](const Studentas &s1, const Studentas &s2){
                return s1.galutinis_med > s2.galutinis_med;
            });
        }
        
    }

    while(!stud.empty()){
        if((pasirinkimas == "V" || pasirinkimas == "v") && stud.back().galutinis_vid < 5.0){
            stud_Vargsiukai.push_back(stud.back());
            stud.pop_back();
        }
        else if((pasirinkimas == "M" || pasirinkimas == "m") && stud.back().galutinis_med < 5.0){
            stud_Vargsiukai.push_back(stud.back());
            stud.pop_back();
        }
        else{
            break;
        }
    }

}


// Funkcija, kuri surūšiuoja studentus į dvi grupes, jei vartotojo pasirinkta duomenų struktūra yra vektorius, tai rūšiuojama pagal pirmą strategiją,
// jei duomenų struktūra - sąrašas, tai rūšiuojama pagal 2 strategiją.
template <typename Container>
void Kategorijos_Priskirimas3(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas){

    std::stable_partition(stud.begin(), stud.end(), [&](const auto &studentas){
        if (pasirinkimas == "V" || pasirinkimas == "v"){
            return studentas.galutinis_vid >= 5.0;
        }
        return studentas.galutinis_med >= 5.0;
    });

    while(!stud.empty()){
        if((pasirinkimas == "V" || pasirinkimas == "v") && stud.back().galutinis_vid < 5.0){
            stud_Vargsiukai.push_back(stud.back());
            stud.pop_back();
        }
        else if((pasirinkimas == "M" || pasirinkimas == "m") && stud.back().galutinis_med < 5.0){
            stud_Vargsiukai.push_back(stud.back());
            stud.pop_back();
        }
        else{
            break;
        }
    }
}


// Funkcija, kuri įrašo į failą pateiktą kontainerį.
template <typename Container>
void FailasPgalKategorija(Container &studentai, string pasirinkimas, string isvedimo_pasirinkimas, string pav){
    ofstream failas;

    failas.open(pav);

    if (!failas.is_open()){
        cout << "Klaida atidarant failą. " << endl;
    }

    // Antraštė
    Rez_antraste(pasirinkimas, failas, isvedimo_pasirinkimas);

    for(auto &s : studentai){
        Stud_spausdinimas(s, failas, pasirinkimas, isvedimo_pasirinkimas);
    }

    failas.close();

    cout << "Rezultatas sėkmingai įrašytas į "<< pav <<" failą!" << endl;
}

// Funkcija, skirta vartotojui pasirinkti programos vykdymą (Įvesti - I, Nuskaityti - N, Sugeneruoti - S, Testuoti - T).
string pasirinkimas_del_programos_vykdymo(){
    string ivedimo_skaitymo_p;
    cout << "Pasirinkite ar norite duomenis įvesti, nuskaityti juos iš failo, sugeneruoti ar testuoti duomenų failą?(Įvesti - I, Nuskaityti - N, Sugeneruoti - S, Testuoti - T) ";
    while(true){
        cin >> ivedimo_skaitymo_p;

        // Išimčių tvarkymas skirtas ivedimo ar skaitymo pasirinkimui.
        try{
            if(ivedimo_skaitymo_p != "N" && ivedimo_skaitymo_p != "n" && ivedimo_skaitymo_p != "I" && ivedimo_skaitymo_p != "i" && ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "s" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "t"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp: 'I', 'N', 'S', 'T'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    return ivedimo_skaitymo_p;
}

// Funkcija, skirta vartotojui pasirinkti duomenų struktūrą (V - vektorius, S - sąrašas).
string pasirinkimas_del_duom_strukturos(){
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
    return vektorius_arba_sarasas;
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

            if(rusiavimo_p != "VP" && rusiavimo_p != "vp" && rusiavimo_p != "Vp" && rusiavimo_p != "vP" && rusiavimo_p != "PV" && rusiavimo_p != "pv" && rusiavimo_p != "Pv" && rusiavimo_p != "pV" && rusiavimo_p != "GM" && rusiavimo_p != "gm" && rusiavimo_p != "Gm" && rusiavimo_p != "gM" && rusiavimo_p != "GD" && rusiavimo_p != "gd" && rusiavimo_p != "Gd" && rusiavimo_p != "gD" ){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'VP', 'PV', 'GM' arba 'GD'. ");
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

// Funkcija, skirta vartotojui pasirinkti pagal kurią strategiją norimą skirstyti studentus į dvi grupes (1, 2, 3).
int pasirinkimas_del_strategijos(){
    int kategorijos_pasirinkimas;
    cout << "Pasirinkite kategorijos priskirimo strategija (1 Strategija - įveskite 1, 2 Strategija - 2, 3 Strategija - 3): ";

    while(true){
        cin >> kategorijos_pasirinkimas;

        if (cin.fail()){
            cin.clear();
            cin.ignore();

            try{
                throw invalid_argument("Įvestis nėra skaičius. Turite pasirinkti tarp: '1', '2', '3' strategijų. ");
            } catch (const invalid_argument &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
            }
            continue;
        }
        try{
            if(kategorijos_pasirinkimas != 1 && kategorijos_pasirinkimas != 2 && kategorijos_pasirinkimas != 3){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp: '1', '2', '3' strategijų. ");
            }
            break;

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }
    return kategorijos_pasirinkimas;
}

// Funkcija skirta duomenų tvarkymui, tai rezultatų įrašymui, kategorijos priskirimui, naujų failų sukūrimui.
template <typename Container>
void Duom_tvarkymas(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis){
        cout << endl;
        SpausdinimasRez(stud, kiekis, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);
        cout << endl;

        if (kategorijos_strategija == 1){
            // Studentų rūšiavimas į dvi grupes pagal 1 strategiją.
            Timer t1;
            Kategorijos_Priskirimas1(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas);
            cout << "Failo iš "<< kiekis << " įrašų rūšiavimas į dvi grupes laikas: " << t1.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 2){
            // Studentų rūšiavimas į dvi grupes pagal 2 strategiją.
            Timer t1;
            Kategorijos_Priskirimas2(stud, stud_Vargsiukai, rez_pasirinkimas);
            cout << "Failo iš "<< kiekis << " įrašų rūšiavimas į dvi grupes laikas: " << t1.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 3){
            // Studentų rūšiavimas į dvi grupes pagal 3 strategiją.
            Timer t1;
            Kategorijos_Priskirimas3(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas);
            cout << "Failo iš "<< kiekis << " įrašų rūšiavimas į dvi grupes laikas: " << t1.elapsed() << " s.\n";
            cout << endl;
        }

        // Surūšiuojami pagal vartotojo pasirinkimą, nes skaidymo metu duomenis buvo sumaišyti.
        Studentu_rusiavimas(stud_Vargsiukai, rusiavimo_p, rez_pasirinkimas);
        Studentu_rusiavimas(stud, rusiavimo_p, rez_pasirinkimas);
        

        // Studentai įrašomi į Vargsiukai.txt failą
        Timer t2;
        FailasPgalKategorija(stud_Vargsiukai, rez_pasirinkimas, isvedimo_pasirinkimas, "Vargsiukai.txt");
        cout << "Failo iš "<< kiekis << " įrašų vargšelių įrašymas į failą laikas: " << t2.elapsed() << " s.\n";
        cout << endl;
        
        // Studentai įrašyti i Kietiakai.txt failą
        if (kategorijos_strategija == 1){
            Timer t3;
            FailasPgalKategorija(stud_Kietiakai, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
            cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 2){
            Timer t3;
            FailasPgalKategorija(stud, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
            cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 3){
            if constexpr (is_same_v<Container, vector<Studentas>>){
                Timer t3;
                FailasPgalKategorija(stud, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
                cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
                cout << endl;
            } else if constexpr (is_same_v<Container, list<Studentas>>){
                Timer t3;
                FailasPgalKategorija(stud, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
                cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
                cout << endl;
            }
        }

}

template void Duom_tvarkymas<vector<Studentas>>(vector<Studentas> &stud, vector<Studentas> &stud_Vargsiukai, vector<Studentas> &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);
template void Duom_tvarkymas<list<Studentas>>(list<Studentas> &stud, list<Studentas> &stud_Vargsiukai, list<Studentas> &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);

