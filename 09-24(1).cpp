#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a = 9;
    int b = 9;
    int c = 4;
    int d = 8;

    double vidurkis = (a+b+c+d)/4;

    if (vidurkis >= 5) {
        cout<<"Vidurkis teigiamas"<<endl;
    }
    if (vidurkis < 5) {
        cout<<"Vidurkis neigiamas"<<endl;
    }

    return 0;
}
