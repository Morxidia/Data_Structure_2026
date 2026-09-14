#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int total;
    string operasi;
    cout << "Inputkan nilai a: ";
    cin >> a;
    cout << "Inputkan nilai b: ";
    cin >> b;
    cout << "Inputkan Operasi: ";
    cin >> operasi;

    if (operasi == "+") {
        total = a + b;
    } else if (operasi == "-") {
        total = a - b;
    } else if (operasi == ":") {
        total = a / b;
    }
    
    cout << "Hasilnya: " << total;
    


    return 0;
}