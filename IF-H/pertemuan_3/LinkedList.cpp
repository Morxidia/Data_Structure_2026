#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *buatNode(int nilai)
{
    // initialization for the Node first time in heap memory
    Node *newNode = new Node{nilai, nullptr};
    return newNode;
}

void tampilkan(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << " - ";
            current = current->next;
        }
        else
        {
            cout << " -- end of data" << endl;
            return;
        }
    }
    return;
}

void tambahAwal(Node *&head, int nilai)
{
    Node *newNode = buatNode(nilai);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void tambahAkhir(Node *&head, int nilai)
{
    Node *newNode = buatNode(nilai);
    Node *current = head;

    if (head == nullptr)
    {
        tambahAwal(head, nilai);
    }
    else
    {
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

Node *cari(Node *head, int nilai)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *current = head;
    while (current->next != nullptr && current->data != nilai)
    {
        current = current->next;
    }

    if (current->data != nilai)
    {
        return nullptr;
    }
    else
    {
        return current;
    }
}

bool hapusData(Node *&head, int nilai)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *current = head;
    Node *sebelum = nullptr;
    while (current->next != nullptr && current->data != nilai)
    {
        sebelum = current;
        current = current->next;
    }

    if (current->data != nilai)
    {
        return false;
    }
    else if (current == head)
    {
        head = current->next;
        delete current;
    }
    else if (current->next != nullptr)
    {
        sebelum->next = current->next;
        delete current;
        return true;
    }
    else
    {
        sebelum->next = nullptr;
        delete current;
        return true;
    }
    return true;
}

void clear(Node *&head)
{
    Node *current = head;
    Node *sebelum = nullptr;
    while (current->next != nullptr)
    {
        sebelum = current;
        current = current->next;
        delete sebelum;
    }
    delete current;
    head = nullptr;
}

int main()
{
    Node *head = nullptr; // initilisasi head dengan node 0
    tambahAwal(head, 10);
    tambahAwal(head, 1);
    tambahAwal(head, 15);
    tambahAkhir(head, 30);
    tambahAkhir(head, 43);
    tambahAkhir(head, 38);
    // 15 1 10 30 43 38
    tampilkan(head);
    cout << (hapusData(head, 15) ? "Berhasil" : "Gagal") << endl;
    cout << (hapusData(head, 99) ? "Berhasil" : "Gagal") << endl;
    tampilkan(head);

    cout << (cari(head, 15) != nullptr ? "Berhasil" : "Gagal") << endl;
    cout << (cari(head, 30) != nullptr ? "Berhasil" : "Gagal") << endl;
    Node *nodeCari = cari(head, 15);
    cout << nodeCari->data << endl;
    if (nodeCari != nullptr)
    {
        cout << nodeCari->data << endl;
    }
    else
    {
        cout << "data tidak ada" << endl;
    }
}