#include <iostream>
using namespace std;

int main() {
    int skaicius;
    cout<<"Įveskite dviženklį skaičių: ";
    cin>>skaicius;

    if (skaicius >= 10 && skaicius <= 99) {
        int desimtys = skaicius / 10;
        int vienetai = skaicius % 10;
        int suma = desimtys + vienetai;

        cout<<"Skaitmenų suma: "<<suma<<endl;
    } else {
        cout<<"Tai nėra dviženklis skaičius."<<endl;
    }

    return 0;
}
