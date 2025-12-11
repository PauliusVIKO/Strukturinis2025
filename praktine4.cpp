#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ITEMS = 10;
const double TAX_RATE = 0.21;

struct menumaistasType {
    string menumaistas;
    double menukaina;
};

void getData(menumaistasType menuList[], int& count) {
    ifstream inFile("menu.txt");
    count = 0;
    while (!inFile.eof() && count < MAX_ITEMS) {
        inFile >> menuList[count].menumaistas >> menuList[count].menukaina;
        count++;
    }
    inFile.close();
}

void showMenu(menumaistasType menuList[], int count) {
    cout<<"Pusryčių meniu: "<<endl<<endl;
    for (int i = 0; i < count; i++) {
        string name = menuList[i].menumaistas;
        for (auto& c : name) if (c == '_') c = ' ';
        cout<<setw(2) << i + 1 << ". " << left << setw(35)<<name
             <<right<<fixed<<setprecision(2)<<menuList[i].menukaina<<"€"<<endl;
    }
    cout<<endl<<"Įveskite patiekalo numerį ir porcijų kiekį."<<endl;
    cout<<"Įveskite 0 kad užbaigtumėte pasirinkimą."<<endl<<endl;
}

void printCheck(menumaistasType menuList[], int count, int kiekis[]) {

    double suma = 0.0;
    ofstream out("receipt.txt");

    cout<<endl<<"SĄSKAITA:"<<endl;
    out<<"SĄSKAITA:"<<endl;

    for (int i = 0; i < count; i++) {
        if (kiekis[i] > 0) {
            double subtotal = kiekis[i] * menuList[i].menukaina;
            suma += subtotal;

            string name = menuList[i].menumaistas;
            for (auto& c : name) if (c == '_') c = ' ';

            cout<<setw(2) << kiekis[i] << " "
                 <<left<<setw(30)<<name
                 <<right<<fixed<<setprecision(2)<<subtotal<<"€"<<endl;

            out<<setw(2) << kiekis[i] << " "
                <<left<<setw(30) <<name
                <<right<<fixed<<setprecision(2)<<subtotal<<"€"<<endl;
        }
    }

    double tax = suma * TAX_RATE;
    double total = suma + tax;

    cout<<endl<<"Mokesčiai (21%)"<<setw(20)<<fixed<<setprecision(2)<<tax<<"€"<<endl;
    cout<<"Galutinė suma"<<setw(21)<<fixed<<setprecision(2)<<total<<"€"<<endl;

    out<<endl<<"Mokesčiai (21%)"<<setw(20)<<fixed<<setprecision(2)<<tax<<"€"<<endl;
    out<<"Galutinė suma"<<setw(21)<<fixed<<setprecision(2)<<total<<"€"<<endl;

    out.close();
}

int main() {

    menumaistasType menuList[MAX_ITEMS];
    int count = 0;
    int kiekis[MAX_ITEMS] = {0};

    getData(menuList, count);

    cout<<"Sveiki atvykę į restoraną \"Pavadinimas\""<<endl<<endl;

    showMenu(menuList, count);

    int item, qty;
    while (true) {
        cout<<"Pasirinkite patiekalą (0 - baigti): ";
        cin>>item;
        if (item == 0) break;
        if (item < 1 || item > count) {
            cout << "Neteisingas pasirinkimas!"<<endl;
            continue;
        }
        cout<<"Porcijų kiekis: ";
        cin>>qty;
        if (qty <= 0) {
            cout<<"Neteisingas kiekis!"<<endl;
            continue;
        }
        kiekis[item - 1] += qty;
    }

    printCheck(menuList, count, kiekis);

    return 0;
}
