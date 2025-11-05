#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void bilietuAtaskaita() {
    ifstream inFile("bilietai.txt");
    ofstream outFile("sales_report.txt");

    double bilietoKaina;
    int parduotaBilietu;
    long long visoBilietu = 0;
    double visoSuma = 0;

    while (inFile >> bilietoKaina >> parduotaBilietu) {
        visoBilietu += parduotaBilietu;
        visoSuma += bilietoKaina * parduotaBilietu;
    }

    inFile.close();

    cout<<fixed<<setprecision(2);
    outFile<<fixed << setprecision(2);
    outFile<<"Iš viso parduota bilietų: "<<visoBilietu<<endl;
    outFile<<"Bendra pardavimų suma: "<<visoSuma<<" EUR"<<endl;
    outFile.close();

    cout<<"Rezultatai išsaugoti faile 'sales_report.txt'."<<endl;
}
void atlyginimuSkaiciavimas() {
    ifstream inFile("salary.txt");
    ofstream outFile("newSalary.txt");

    string pavarde, vardas;
    double atlyginimas, procentas;
    int eilNr = 0;

    cout << fixed << setprecision(2);
    outFile << fixed << setprecision(2);

    cout<<"Atlyginimų skaičiavimas:"<<endl;

    while (inFile >> pavarde >> vardas >> atlyginimas >> procentas) {
        double naujasAtlyginimas = atlyginimas * (1 + procentas / 100.0);
        cout<<pavarde<<" "<<vardas<<" "<<naujasAtlyginimas<<endl;
        outFile<<pavarde<<" "<<vardas<<" "<<naujasAtlyginimas<<endl;
        eilNr++;
    }

        cout<<"Rezultatai išsaugoti faile 'newSalary.txt'."<<endl;

    inFile.close();
    outFile.close();
}

void meniu() {
    int pasirinkimas;
    do {
        cout<<"Duomenų apdorojimo sistema"<<endl;
        cout<<"1. Futbolo bilietų ataskaita"<<endl;
        cout<<"2. Atlyginimų skaičiavimas"<<endl;
        cout<<"3. Išeiti"<<endl;
        cout<<"Pasirinkite (1-3): ";
        cin>>pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                bilietuAtaskaita();
                break;
            case 2:
                atlyginimuSkaiciavimas();
                break;
            case 3:
                cout<<"Geros dienos!"<<endl;
                break;
            default:
                cout<<"Neteisingas pasirinkimas! Pasirinkite skaičius skliausteliuose: "<<endl;
        }
    } while (pasirinkimas != 3);
}

int main() {
    meniu();
    return 0;
}
