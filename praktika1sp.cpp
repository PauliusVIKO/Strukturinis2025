#include <iostream>

using namespace std;

int main() {
    string valiuta;
    double suma;
    char buysell;

    double gbp = 0.8729;
    double usd = 1.1793;
    double inr = 104.6918;
    double gbpbuy = 0.8600;
    double usdbuy = 1.1460;
    double inrbuy = 101.3862;
    double gbpsell = 0.9220;
    double usdsell = 1.2340;
    double inrsell = 107.8546;
    
    cout<<"Įveskite valiutą, kurią norite įsigyti (GBP, USD, INR): "<<endl;
    cin>>valiuta;
    
    cout<<"Pirkti (B) ar parduoti (S)? "<<endl;
    cin>>buysell;
    
    cout<<"Įveskite sumą: "<<endl;
    cin>>suma;
    
    if (valiuta == "gbp" || valiuta == "GBP") {
        if (buysell == 'b' || buysell == 'B') {
            cout<<"Už "<<suma<<" € = "<<suma*gbpbuy<<" £."<<endl;
        } else if (buysell  == 's' || buysell == 'S') {
            cout<<"Už "<<suma<<" £ = "<<gbpsell/suma<<" €."<<endl;
        }
    }
    
    if (valiuta == "usd" || valiuta == "USD") {
        if (buysell == 'b' || buysell == 'B') {
            cout<<"Už "<<suma<<" € = "<<suma*usdbuy<<" $."<<endl;
        } else if (buysell  == 's' || buysell == 'S') {
            cout<<"Už "<<suma<<" $ = "<<usdsell/suma<<" €."<<endl;
        }
    }
    
    if (valiuta == "inr" || valiuta == "INR") {
        if (buysell == 'b' || buysell == 'B') {
            cout<<"Už "<<suma<<" € = "<<suma*inrbuy<<" ₹."<<endl;
        } else if (buysell  == 's' || buysell == 'S') {
            cout<<"Už "<<suma<<" ₹ = "<<suma/inrsell<<" €."<<endl;
        }
    }
    
    return 0;
}
