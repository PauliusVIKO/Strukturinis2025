#include <iostream>
using namespace std;

int main() {
    int a = 0;

    for (int i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            a += i;
        }
    }

    cout<<"Nelyginių skaičių suma intervale [1; 20] yra: "<<a<<endl;

    return 0;
}
