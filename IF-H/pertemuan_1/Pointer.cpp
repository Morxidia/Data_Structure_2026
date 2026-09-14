#include <iostream>
using namespace std;

struct Mahasiswa
{
    string NIM;
    string nama;
};

void gantiNama(Mahasiswa *obj, string newName)
{
    (*obj).nama = newName;
    // obj->nama = newName;
}

int main()
{
    Mahasiswa *juju = new Mahasiswa();
    Mahasiswa jiorno;
    jiorno.nama = "jojo";
    jiorno.NIM = "0809900";
    cout << jiorno.nama << endl;
    gantiNama(&jiorno, "giovarni giorgio");
    cout << jiorno.nama << endl;
}