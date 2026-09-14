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

bool tambahData(Node *&head, int nilai)
{
    Node *newNode = buatNode(nilai);
    Node *current = head;
    // null pointer head
    if (head == nullptr)
    {
        head = newNode;
        return true;
    }
    if (head->data > nilai)
    {
        newNode->next = head;
        head = newNode;
        return true;
    };

    while (current->next != nullptr)
    {
        if (current->data < nilai && current->next->data > nilai)
        {
            newNode->next = current->next;
            current->next = newNode;
            return true;
        }
        current = current->next;
    }

    if (current->next == nullptr)
    {
        current->next = newNode;
        return true;
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
    tambahData(head, 32);
    tampilkan(head);
    tambahData(head, 12);
    tampilkan(head);
    tambahData(head, 2);
    tampilkan(head);
    tambahData(head, 52);
    tampilkan(head);
    tambahData(head, 9);
    tampilkan(head);
    tambahData(head, 3);
    tampilkan(head);
    tambahData(head, 40);
    tampilkan(head);
}