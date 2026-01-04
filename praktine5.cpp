#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Studentas {
    string id;
    string atsakymai;
    int taskai;
    double procentai;
    int pazymys;
};

int calculateGrade(double procentai);
void printClassStatistics(const vector<Studentas>& studentai);
void searchStudentByID(const vector<Studentas>& studentai);
void saveResultsToFile(const vector<Studentas>& studentai, const string& filename);
void questionStatistics(const vector<Studentas>& studentai, const string& teisingasats);

int main() {
    ifstream inputFile("testData.txt");

    string teisingasats;
    getline(inputFile, teisingasats);

    vector<Studentas> studentai;
    string id, studentoats;

    while (inputFile >> id) {
        inputFile.ignore();
        getline(inputFile, studentoats);

        int score = 0;

        for (int i = 0; i < 20; i++) {
            if (i < studentoats.length()) {
                char ans = studentoats[i];
                if (ans == teisingasats[i]) {
                    score += 2;
                } else if (ans == 'T' || ans == 'F') {
                    score -= 1;
                }
            }
        }

        double percent = (score / 40.0) * 100;
        if (percent < 0) percent = 0;

        Studentas s;
        s.id = id;
        s.atsakymai = studentoats;
        s.taskai = score;
        s.procentai = percent;
        s.pazymys = calculateGrade(percent);

        studentai.push_back(s);
    }
    inputFile.close();

    printClassStatistics(studentai);
    questionStatistics(studentai, teisingasats);
    saveResultsToFile(studentai, "results.txt");
    searchStudentByID(studentai);

    return 0;
}

int calculateGrade(double p) {
    if (p >= 95) return 10;
    if (p >= 85) return 9;
    if (p >= 75) return 8;
    if (p >= 65) return 7;
    if (p >= 55) return 6;
    if (p >= 50) return 5;
    if (p >= 35) return 4;
    if (p >= 25) return 3;
    if (p >= 15) return 2;
    return 1;
}

void printClassStatistics(const vector<Studentas>& studentai) {
    if (studentai.empty()) return;

    double sumScore = 0, sumPercent = 0;
    int maxG = studentai[0].pazymys, minG = studentai[0].pazymys;
    int paskirstymas[11] = {0};

    for (const auto& s : studentai) {
        sumScore += s.pazymys;
        sumPercent += s.procentai;
        if (s.pazymys > maxG) maxG = s.pazymys;
        if (s.pazymys < minG) minG = s.pazymys;
        paskirstymas[s.pazymys]++;
    }

    cout<<"Studentų skaičius: "<<studentai.size()<<endl;
    cout<<"Didžiausias balas: "<<maxG<<", Mažiausias balas: "<<minG<<endl;
    cout<<"Vidutinis pažymys: "<<fixed<< setprecision(2)<<sumScore / studentai.size()<<endl;
    cout<<"Vidutinis procentas: "<<sumPercent / studentai.size()<<"%"<<endl;
    cout<<"Pažymių paskirstymas:"<<endl;
    for (int i = 1; i <= 10; i++) {
        cout<<i<<" balų: "<<paskirstymas[i]<<" studentai(-u)"<<endl;
    }
}

void searchStudentByID(const vector<Studentas>& studentai) {
    string searchID;
    while (true) {
        cout<<"Įveskite studento ID (arba 0, kad baigti): ";
        cin>>searchID;
        if (searchID == "0") {
            cout<<"Geros dienos!"<<endl;
            break;
        }

        bool found = false;
        for (const auto& s : studentai) {
            if (s.id == searchID) {
                cout<<"Rastas studentas: ID "<<s.id<<" | Taškai: "<<s.taskai<<" | Procentai: "<<s.procentai<<"% | Pažymys: "<<s.pazymys<<endl;
                found = true;
                break;
            }
        }
        if (!found) cout<<"Studentas su ID "<<searchID<<" nerastas."<<endl;
    }
}

void saveResultsToFile(const vector<Studentas>& studentai, const string& filename) {
    ofstream outFile(filename);
    outFile<<left<<setw(15)<<"ID"<<setw(10)<<"Taškai"<<setw(12)<<"Procentai"<<"Pažymys"<<endl;
    for (const auto& s : studentai) {
        outFile<<left<<setw(15)<<s.id<<setw(10)<<s.taskai<<fixed<<setprecision(1)<<setw(12)<<s.procentai<<s.pazymys<<endl;
    }
    outFile.close();
    cout<<endl;
    cout<<"Rezultatai išsaugoti faile: "<<filename<<endl;
}

void questionStatistics(const vector<Studentas>& studentai, const string& correctAnswers) {
    vector<double> correctPercents(20);

    for (int i = 0; i < 20; i++) {
        int right = 0, wrong = 0, skipped = 0;
        for (const auto& s : studentai) {
            char ans = (i < s.atsakymai.length()) ? s.atsakymai[i] : ' ';
            if (ans == correctAnswers[i]) right++;
            else if (ans == 'T' || ans == 'F') wrong++;
            else skipped++;
        }
        correctPercents[i] = (double)right / studentai.size() * 100;
        cout<<i+1<<" klausimas: Teisingai: "<<right<<", Neteisingai: "<<wrong<<", Neatsake: "<<skipped<<endl;
    }

    double minPercent = *min_element(correctPercents.begin(), correctPercents.end());
    cout<<endl;
    cout<<"Sunkiausias(-i) klausimas(-ai) (mažiausias teisingų atsakymų %: "<<minPercent<<"%):"<<endl;
    for (int i = 0; i < 20; i++) {
        if (correctPercents[i] == minPercent) {
            cout<<"Klausimo numeris: "<<i + 1<<endl;
        }
    }
}
