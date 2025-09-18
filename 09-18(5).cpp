#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    double skaicius1, skaicius2, skaicius3, skaicius4, skaicius5;

    cout<<"Įveskite 1 skaičių: ";
    cin>>skaicius1;
    
    cout<<"Įveskite 2 skaičių: ";
    cin>>skaicius2;
    
    cout<<"Įveskite 3 skaičių: ";
    cin>>skaicius3;
    
    cout<<"Įveskite 4 skaičių: ";
    cin>>skaicius4;
    
    cout<<"Įveskite 5 skaičių: ";
    cin>>skaicius5;

    cout<<"Skaičių vidurkis yra: "<<(skaicius1 + skaicius2 + skaicius3 + skaicius4 + skaicius5) / 5<<endl;

 
    return 0;
}
