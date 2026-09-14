#include <iostream>
using namespace std;

struct Mahasiwa{
    string NIM;
    string Nama;
};

void gantiNama(Mahasiwa* mhs, string namaBaru){
    // (*mhs).Nama = namaBaru;
    mhs->Nama = namaBaru;
}

int main(void){
    Mahasiwa guntur;
    guntur.NIM = "12328077";
    guntur.Nama = "Kesamber Geledek";
    cout << "nama sebelum : " << guntur.Nama << endl;
    gantiNama(&guntur, "Guntur");
    cout << "nama sebelum : " << guntur.Nama << endl;
}
