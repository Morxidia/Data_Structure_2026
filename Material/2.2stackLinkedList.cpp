#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedStack {
    Node* top;
};

bool push(LinkedStack& s, int nilai) {
    s.top = new Node{nilai, s.top};
    return true;
}

bool pop(LinkedStack& s, int& nilaiKeluar) {
    if (s.top == nullptr) return false;
    Node* hapus = s.top;
    nilaiKeluar = hapus->data;
    s.top = s.top->next;
    delete hapus;
    return true;
}

void tampilkanStack(LinkedStack& s) {
    if (s.top == nullptr) {
        cerr << "Stack Kosong\n";
        return;
    }
    cout << "Isi Stack (Top -> Bottom): ";
    for (Node* i = s.top; i != nullptr; i=i->next) {
        cout << i->data << " ";
    }
    cout << endl;
}


bool clearStack(LinkedStack& s){
    while(s.top != nullptr){
        Node* temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
    s.top = nullptr;
    return true;
}

int main(void){

}