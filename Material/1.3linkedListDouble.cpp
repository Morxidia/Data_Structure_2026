#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node *prev;
};

Node* buatNode(int nilai) {
    return new Node{nilai, nullptr};
}

void tampilkan(const Node* head) {
    const Node* bantu = head;
    while (bantu != nullptr) {
        std::cout << bantu->data << ' ';
        bantu = bantu->next;
    }
    std::cout << '\n';
}

void tambahAwal(Node*& head, int nilai) {
    Node* baru = new Node{nilai, head};
    head = baru;
}

void tambahAkhir(Node*& head, int nilai) {
    Node* baru = new Node{nilai, nullptr};
    if (head == nullptr) {
        head = baru;
        return;
    }

    Node* bantu = head;
    while (bantu->next != nullptr)
        bantu = bantu->next;

    bantu->next = baru;
}

Node* cari(Node* head, int nilai) {
    Node* bantu = head;
    while (bantu != nullptr) {
        if (bantu->data == nilai)
            return bantu;
        bantu = bantu->next;
    }
    return nullptr;
}

bool hapusData(Node*& head, int nilai) {
    if (head == nullptr) return false;

    Node* target = head;
    Node* sebelum = nullptr;

    while (target != nullptr && target->data != nilai) {
        sebelum = target;
        target = target->next;
    }

    if (target == nullptr) return false;

    if (sebelum == nullptr)
        head = target->next;
    else
        sebelum->next = target->next;

    delete target;
    return true;
}

void clear(Node*& head) {
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main(void){

}