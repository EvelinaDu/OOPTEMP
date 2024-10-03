#include "Stud.h"

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

// Funkcija, kuri generuoja studento namų darbų ir egzamino įvertinimus.
void Duom_generavimas(Studentas &s, int nd_kiekis){

    int min_rezult = 1;
    int max_result = 10;

    //Atsitiktiniu skaičiu generatorius
    random_device rd_genrator;   
    // Intervalas atsitiktinei reikšmei
    uniform_int_distribution<int> Ivertinimas(min_rezult, max_result);


// Sugeneruoja namų darbų įvertinimus pagal nurodyta kiekį.
    for(int i = 0; i < nd_kiekis; i++){

        int nd_ivertinimas = Ivertinimas(rd_genrator);
        cout << nd_ivertinimas << " ";
        s.nd.push_back(nd_ivertinimas);

    }

    s.egz = Ivertinimas(rd_genrator);
    cout << s.egz << endl;
}

// Funkcija skirta nuskaityti studento įvertinimus iš failo.
void Stud_is_failo(Studentas &s, string eil){
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
    else if(p == "VM" || p == "vm"){
        out << setw(15) << left << s.vardas << setw(16) << left << s.pavarde << setw(18) << left << fixed << setprecision(2) << s.galutinis_vid << setw(16) << left << s.galutinis_med << endl;
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
    else if(pasirinkimas == "VM" || pasirinkimas == "vm"){
        out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.)  " << setw(16) << left << "Galutinis (Med.)" << endl;
        out << "-------------------------------------------------------------------" << endl;
    }
}

// Funkcija skirta studentų vektoriui surušiuoti, rušiuojama pagal vardus, tačiau kai vardai sutampa, rušiuojama pagal pavardes.
void Studentu_rusiavimas(vector<Studentas> &stud){
    sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
        if(s1.vardas != s2.vardas){
            return s1.vardas < s2.vardas;
        }
        return s1.pavarde < s2.pavarde;
    });

}

// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
void SpausdinimasRez(vector<Studentas> &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas){
    ofstream failasOut;

    if(isvedimo_pasirinkimas == "T" || isvedimo_pasirinkimas == "t"){
        Rez_antraste(rez_pasirinkimas, cout);
        for (int i = 0; i < n; i++){
        Ivertinimas_vid(stud[i]);
        Ivertinimas_med(stud[i]);
        Stud_spausdinimas(stud.at(i), cout, rez_pasirinkimas);
    }
    }
    else if (isvedimo_pasirinkimas == "F" || isvedimo_pasirinkimas == "f"){
        failasOut.open("Rez.txt");

        if(failasOut.is_open()){
            Rez_antraste(rez_pasirinkimas, failasOut);
            for (int i = 0; i < n; i++){
                Ivertinimas_vid(stud[i]);
                Ivertinimas_med(stud[i]);
                Stud_spausdinimas(stud.at(i), failasOut, rez_pasirinkimas);
            }
            failasOut.close();
            cout << "Rezultatas įrašytas Rez.txt faile" << endl;
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
