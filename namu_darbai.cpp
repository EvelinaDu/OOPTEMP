#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>   // sort() funkcijai
#include <cstdlib>     // rand() ir srand() funkcijoms
#include <ctime>       // Leidžia dirbti su laiku, funkcija time()

#include <chrono>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;
using std::stringstream;

// Studento struktūra, kuri susideda iš vardo, pavardes, namų darbų vektoriaus, egzamino ir įvertinimu.
struct Studentas{
  string vardas, pavarde;
  vector <double> nd;
  double egz, galutinis_vid, galutinis_med;
};

// Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
void Duom_ivedimas(Studentas &s){

    cout << "Įveskite visus namų darbų įvertinimus. Norėdami baigti įvedimą spauskite dukart 'Enter' klavišą" << endl;
    string input;        // Kintamasis įvesties eilutei saugoti
    int ivertinimas;

    // While ciklas, skirtas įrašyti studento namų darbų įvertinimus. Vyksta tol kol vartotojas nuspaudžia du kart "Enter".
    while(true){
        getline(cin, input);   // Įvedama visą eilutė
        if(input.empty()){     // Jei įvestis tuščia (buvo nuspaustas 'Enter'), nutraukiamas ciklas.  
            break;
        }

        stringstream ss(input);
        if(ss >> ivertinimas){
            s.nd.push_back(ivertinimas);
        }
        else{
            cout << "Netinkama įvestis, bandykite dar kartą." << endl;
        }
    }

    cout << "Įveskite studento egzamino įvertinimą: ";
    cin >> s.egz;
    // cin.ignore() pašalina visus likusius simbolius iš įvesties srauto iki pirmo naujos eilutės simbolio.
    cin.ignore(); 

}

// Funkcija, kuri generuoja studento namų darbų ir egzamino įvertinimus.
void Duom_generavimas(Studentas &s){
    cout << "Įveskite studento vardą: ";
    cin >> s.vardas;

    cout << "Įveskite studento pavarde: ";
    cin >> s.pavarde;

    int nd_kiekis;
    cout << "Kiek namų darbų norėtumėt, kad būtų sugeneruota? ";
    cin >> nd_kiekis;

    int nd_nr = 1;
    // srand - tai funkcija, kuri nustato atsitiktinių skaičių generatoriaus pradžios tašką.
    // time(0) - ši funkcija grąžina dabartinį laiką sekundėmis.
    srand(time(0));

// Sugeneruoja namų darbų įvertinimų kiekį, kurį nurodo vartotojas.
    for(int i = 0; i < nd_kiekis; i++){

        int nd_ivertinimas = rand() % 10 + 1;   // rand() % 10 - sugeneruoja atsitiktini skaičių nuo 0-9, todėl dar pridedame 1, kad gautume intervalą 1-10.

        cout << nd_nr <<" Namų darbų" << " įvertinimas: " << nd_ivertinimas << endl;
        s.nd.push_back(nd_ivertinimas);
        nd_nr ++;

    }

    s.egz = rand() % 10 + 1;
    cout << "Egzamino įvertinimas: " << s.egz << endl;
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
    if (nd_kiekis > 0){
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
void Spausdinimas(Studentas &s, string p){
    if(p == "V"){
        cout << setw(15) << left << s.vardas << setw(15) << left << s.pavarde << setw(3) << left << fixed << setprecision(2) << s.galutinis_vid << endl;
    }
    else if(p == "M"){
        cout << setw(15) << left << s.vardas << setw(15) << left << s.pavarde << setw(15) << left << fixed << setprecision(2) << s.galutinis_med << endl;
    }
    else if(p == "VM"){
        cout << setw(15) << left << s.vardas << setw(15) << left << s.pavarde << setw(15) << left << fixed << setprecision(2) << s.galutinis_vid << setw(3) << left << s.galutinis_med << endl;
    }

}

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez(string pasirinkimas){
    
    if(pasirinkimas == "V"){
        cout  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(3) << left << "Galutinis (Vid.)" << endl;
        cout << "------------------------------------------------" << endl;
    }
    else if(pasirinkimas == "M"){
        cout  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(3) << left << "Galutinis (Med.)" << endl;
        cout << "------------------------------------------------" << endl;
    }
    else if(pasirinkimas == "VM"){
        cout  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(3) << left << "Galutinis (Vid.) / " << setw(3) << left << "Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------------------" << endl;
    }
}

// Funkcija, skirta išvalyti studento duomenis.
void valymas(Studentas &s){
    s.vardas.clear();
    s.pavarde.clear();
    s.nd.clear();
    s.egz = 0; 
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();

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