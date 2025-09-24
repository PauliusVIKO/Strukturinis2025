#include <iostream>
using namespace std;

int main() {
    int a = 10;

    switch (a) {
        case 10:
        printf("puiku");
            break;
        case 9:
        printf("labai gerai");
            break;
        case 8:
        case 7:
        printf("gerai");
            break;
        case 6:
        case 5:
        printf("patenkinamai");
            break;
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
        printf("egzaminas neišlaikytas");
            break;
    }

    return 0;
}
