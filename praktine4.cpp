#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ITEMS = 20;
const double TAX_RATE = 0.21;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

void getData(menuItemType menuList[], int& count) {
    ifstream inFile("menu.txt");
    count = 0;
    while (!inFile.eof() && count < MAX_ITEMS) {
        inFile >> menuList[count].menuItem >> menuList[count].menuPrice;
        count++;
    }
    inFile.close();
}

void showMenu(menuItemType menuList[], int count) {
    cout << "Pusryčių meniu: "<<endl<<endl;
    for (int i = 0; i < count; i++) {
        string name = menuList[i].menuItem;
        for (auto& c : name) if (c == '_') c = ' ';
        cout<<setw(2) << i + 1 << ". " << left << setw(35) << name
             <<right<<fixed<<setprecision(2)<<menuList[i].menuPrice << " EUR"<<endl;
    }
    cout << endl<<"Įveskite patiekalo numerį ir porcijų kiekį."<<endl;
    cout << "Įveskite 0 kad užbaigtumėte pasirinkimą."<<endl<<endl;
}

void printCheck(menuItemType menuList[], int count, int quantities[]) {

    double sum = 0.0;
    ofstream out("receipt.txt");

    cout << endl<<"------- SĄSKAITA -------"<<endl;
    out  << "------- SĄSKAITA -------"<<endl;

    for (int i = 0; i < count; i++) {
        if (quantities[i] > 0) {
            double subtotal = quantities[i] * menuList[i].menuPrice;
            sum += subtotal;

            string name = menuList[i].menuItem;
            for (auto& c : name) if (c == '_') c = ' ';

            cout << setw(2) << quantities[i] << " x "
                 << left << setw(30) << name
                 << right << fixed << setprecision(2) << subtotal << " EUR"<<endl;

            out << setw(2) << quantities[i] << " x "
                << left << setw(30) << name
                << right << fixed << setprecision(2) << subtotal << " EUR"<<endl;
        }
    }

    double tax = sum * TAX_RATE;
    double total = sum + tax;

    cout <<endl<<"Mokesčiai (21%)" << setw(20) << fixed << setprecision(2) << tax << " EUR"<<endl;
    cout << "Galutinė suma"   << setw(21) << fixed << setprecision(2) << total << " EUR"<<endl;

    out  <<endl<<"Mokesčiai (21%)" << setw(20) << fixed << setprecision(2) << tax << " EUR"<<endl;
    out  << "Galutinė suma"   << setw(21) << fixed << setprecision(2) << total << " EUR"<<endl;

    out.close();
}

int main() {

    menuItemType menuList[MAX_ITEMS];
    int count = 0;
    int quantities[MAX_ITEMS] = {0};

    getData(menuList, count);

    cout << "Sveiki atvykę į restoraną \"Pavadinimas\"\n"<<endl;

    showMenu(menuList, count);

    int item, qty;
    while (true) {
        cout << "Pasirinkite patiekalą (0 - baigti): ";
        cin >> item;
        if (item == 0) break;
        if (item < 1 || item > count) {
            cout << "Neteisingas pasirinkimas!"<<endl;
            continue;
        }
        cout << "Kiek porcijų? ";
        cin >> qty;
        if (qty <= 0) {
            cout << "Neteisingas kiekis!"<<endl;
            continue;
        }
        quantities[item - 1] += qty;
    }

    printCheck(menuList, count, quantities);

    return 0;
}
