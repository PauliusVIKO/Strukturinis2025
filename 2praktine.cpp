#include <iostream>
#include <string>
using namespace std;

const int MAX_MOK = 100;
const int MAX_PAZYMIU = 10;

int main() {
    string vardai[MAX_MOK];
    int pazymiai[MAX_MOK][MAX_PAZYMIU];
    int pazkiek[MAX_MOK];
    int kiekis = 0, choose;

    do {
        cout<<"MOKINIŲ PAŽYMIAI"<<endl;
        cout<<"Prideti mokini (1)"<<endl;
        cout<<"Parodyti visus (2)"<<endl;
        cout<<"Parodyti vieną (3)"<<endl;
        cout<<"Pakeisti pažymį (4)"<<endl;
        cout<<"Pašalinti mokinį (5)"<<endl;
        cout<<"Išeiti iš programos (6)"<<endl;
        cout<<"Pasirinkite metodą: "<<endl;
        cin>>choose;
        cin.ignore();

        if (choose == 1) {
            if (kiekis >= MAX_MOK) { cout<<"Limitas yra pasiektas."<<endl; continue; }
            cout<<"Vardas: "; getline(cin, vardai[kiekis]);
            cout<<"Pažymių kiekis (1-10): "; cin>>pazkiek[kiekis];
            if (pazkiek[kiekis] < 1 || pazkiek[kiekis] > 10) { cout << "Skaičius yra netinkamas."<<endl; continue; }
            for (int i = 0; i < pazkiek[kiekis]; i++) {
                cout<<i+1<<" pažymys: "; cin>>pazymiai[kiekis][i];
            }
            kiekis++;
            cout << "Sėkmingai pridėta."<<endl;
        }

        else if (choose == 2) {
            if (!kiekis) { cout<<"Yra tusčia"<<endl;; continue; }
            for (int i = 0; i < kiekis; i++) {
                cout << vardai[i] << ": ";
                for (int j = 0; j < pazkiek[i]; j++) cout << pazymiai[i][j]<<" ";
                cout << endl;
            }
        }

        else if (choose == 3) {
            cout<<"Parašykite vardą: "<<endl;;
            string v; getline(cin, v);
            bool r = false;
            for (int i = 0; i < kiekis; i++)
                if (vardai[i] == v) {
                    cout << vardai[i] << ": ";
                    for (int j = 0; j < pazkiek[i]; j++) cout << pazymiai[i][j] << " ";
                    cout << endl; r = true;
                     break;
                }
            if (!r) cout<<"Nėra mokinio, kurio įvedėte jo vardą."<<endl;
        }

        else if (choose == 4) {
            cout<<"Vardas: ";
            string v; getline(cin, v);
            bool r = false;
            for (int i = 0; i < kiekis; i++)
                if (vardai[i] == v) {
                    int nr; cout << "Kelintas pažymys (1-" << pazkiek[i] << "): "; cin >> nr;
                    if (nr < 1 || nr > pazkiek[i]) { cout << "Skaičius yra netinkamas"<<endl; break; }
                    cout << "Naujas pažymys: "; cin >> pazymiai[i][nr-1];
                    cout << "Pažymys yra atnaujintas"<<endl; r = true; break;
                }
            if (!r) cout << "Nerasta."<<endl;
        }

        else if (choose == 5) {
            cout<<"Vardas: ";
            string v; getline(cin, v);
            bool r = false;
            for (int i = 0; i < kiekis; i++)
                if (vardai[i] == v) {
                    for (int j = i; j < kiekis - 1; j++) {
                        vardai[j] = vardai[j + 1];
                        pazkiek[j] = pazkiek[j + 1];
                        for (int k = 0; k < MAX_PAZYMIU; k++)
                            pazymiai[j][k] = pazymiai[j + 1][k];
                    }
                    kiekis--; r = true; cout<<"Pašalinama"<<endl; 
                    break;
                }
            if (!r) cout<<"Komanda nerasta"<<endl;
        }

        else if (choose == 6) {
            cout<<"Geros dienos!"<<endl;
        }

        else {
            cout<<"Pasirinkimas neatitinka metodui daryti."<<endl;
        }

    } while (choose != 6);

    return 0;
}
