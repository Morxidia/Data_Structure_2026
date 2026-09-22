#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *buatNode(int nilai)
{
    Node *newNode = new Node{nilai, nullptr};
    return newNode;
}

void tampilkan(Node *head, Node *last)
{
    Node *current = head;
    if (head == nullptr)
    {
        cout << "List Kosong" << endl;
        return;
    }
    do
    {
        cout << current->data << " - ";
        current = current->next;
    } while (current != head);
    cout << "kembali ke head" << endl;
    return;
}

bool tambahData(Node *&head, Node *&last, int nilai)
{
    Node *newNode = buatNode(nilai);
    Node *current = head;
    // null pointer head
    if (head == nullptr && last == nullptr)
    {
        head = newNode;
        last = newNode;
        newNode->next = head;
        return true;
    }

    if (head->data > nilai)
    {
        // sisip depan
        newNode->next = head;
        head = newNode;
        // ini penting
        last->next = head;
        return true;
    };

    while (current->next != head && current->next->data < nilai)
    {
        current = current->next;
    }

    if (current->next != head)
    {
        // sisip tengah
        newNode->next = current->next;
        current->next = newNode;
        return true;
    }
    else if (current->next == head)
    {
        // sisip akhir
        newNode->next = head;
        current->next = newNode;

        last = newNode;
    }
    return false;
}

Node *cari(Node *head, int nilai)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *current = head;
    while (current->next != head && current->data != nilai)
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

bool hapusData(Node *&head, Node *&last, int nilai)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *current = head;
    Node *sebelum = nullptr;
    while (current->next != head && current->data != nilai)
    {
        sebelum = current;
        current = current->next;
    }

    if (current->data != nilai)
    {
        // data tidak ditemukan
        return false;
    }
    else{

        if (current == head)
        {
            // hapus depan
            if (current->next == head)
            {
                head = nullptr;
                last = nullptr;
            }
            else{
                head = current->next;
                last->next = head;
            }
        }
        else if (current->next != head)
        {
            sebelum->next = current->next;
        }
        else
        {
            // hapus akhir
            sebelum->next = head;
            last = sebelum;
        }
        delete current;
        return true;
    }
    return false;
}

void clear(Node *&head, Node *&last)
{
    if (head == nullptr) return;

    Node *current = head;
    Node *berikut = nullptr;

    do
    {
        berikut = current->next;
        delete current;
        current = berikut;
    } while (current != head);

    head = nullptr;
    last = nullptr;
}

int main()
{
    // initilisasi head dengan node 0
    Node *head = nullptr;
    Node *last = nullptr;
    tambahData(head, last, 32);
    tampilkan(head, last);
    tambahData(head, last, 12);
    tampilkan(head, last);
    tambahData(head, last, 2);
    tampilkan(head, last);
    tambahData(head, last, 52);
    tampilkan(head, last);
    tambahData(head, last, 9);
    tampilkan(head, last);
    tambahData(head, last, 3);
    tampilkan(head, last);
    tambahData(head, last, 40);
    tampilkan(head, last);
}