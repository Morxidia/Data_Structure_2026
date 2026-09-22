#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *buatNode(int nilai)
{
    Node *newNode = new Node{nilai, nullptr, nullptr};
    return newNode;
}

void tampilkanFromHead(Node *head)
{
    if (head == nullptr)
    {
        cout << "List Kosong" << endl;
        return;
    }

    Node *current = head;
    do
    {
        cout << current->data;
        if (current->next != head)
        {
            cout << " <-> ";
        }
        current = current->next;
    } while (current != head);
    cout << " -> back to head (" << head->data << ")" << endl;
}

void tampilkanFromLast(Node *last)
{
    if (last == nullptr)
    {
        cout << "List Kosong" << endl;
        return;
    }

    Node *current = last;
    do
    {
        cout << current->data;
        if (current->prev != last)
        {
            cout << " <-> ";
        }
        current = current->prev;
    } while (current != last);
    cout << " -> back to last (" << last->data << ")" << endl;
}

bool tambahData(Node *&head, Node *&last, int nilai)
{
    Node *newNode = buatNode(nilai);

    // null pointer head
    // initialization of linked list
    if (head == nullptr)
    {
        head = newNode;
        last = newNode;
        head->next = head;
        head->prev = head;
        return true;
    }

    // sisip depan
    if (head->data >= nilai)
    {
        // newnode next-> head, head prev-> newNode
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        last->next = head;
        head->prev = last;
        return true;
    };

    // 10 11 15
    // 13
    // temp 11 next 15

    Node *current = head;
    while (current->next != head && current->next->data < nilai)
    {
        current = current->next;
    }

    if (current->next != head)
    {
        // sisip tengah
        // depan sambung new
        current->next->prev = newNode;
        newNode->next = current->next;
        // current sambung new
        current->next = newNode;
        newNode->prev = current;
        return true;
    }
    else if (current->next == head)
    {
        // sisip belakang
        current->next = newNode;
        newNode->prev = current;
        // perubahan variable last itu diakhir
        last = newNode;
        last->next = head;
        head->prev = last;
        return true;
    }
    return false;
}

Node *cari(Node *head, int nilai)
{
    if (head == nullptr) return nullptr;

    Node *current = head;
    do
    {
        if (current->data == nilai) return current;
        current = current->next;
    } while (current != head);

    return nullptr;
}

bool hapusData(Node *&head, Node *&last, int nilai)
{
    if (head == nullptr)
    {
        // check if the list is empty
        return false;
    }

    Node *current = head;
    while (current->next != head && current->data != nilai)
    {
        current = current->next;
    }

    if (current->data != nilai)
    {
        return false;
    }
    else{
        if (current == head && head == last){
            // jika node hanya berisi satu
            head = nullptr;
            last = nullptr;
        }
        else if (current == head)
        {
            // hapus depan
            head = current->next;
            last->next = head;
            head->prev = last;
        }
        else if (current->next != head)
        {
            // hapus tengah
            // Node *sebelum = current->prev;
            current->prev->next = current->next;
            current->next->prev = current->prev;

        }
        else
        {
            // hapus di akhir
            last = current->prev;
            // sambungkan circular
            last->next = head;
            head->prev = last;
        }
        delete current;
        return true;
    }
    return true;
}

void clear(Node *&head, Node *&last)
{
    if (head == nullptr) return;

    Node *current = head;
    while (current->next != head)
    {
        Node *sebelum = current;
        current = current->next;
        delete sebelum;
    }
    delete current;

    head = nullptr;
    last = nullptr;
}

int main()
{
    Node *head{nullptr};
    Node *last{nullptr};
    tambahData(head, last, 12);
    tampilkanFromHead(head);
    tambahData(head, last, 14);
    tampilkanFromHead(head);
    tambahData(head, last, 15);
    tampilkanFromHead(head);
    tambahData(head, last, 42);
    tampilkanFromHead(head);
    tambahData(head, last, 44);
    tampilkanFromHead(head);
    tambahData(head, last, 12);
    tampilkanFromHead(head);
    tambahData(head, last, 11);
    tampilkanFromHead(head);
    tambahData(head, last, 52);
    cout << "" << endl;
    tampilkanFromHead(head);
    tampilkanFromLast(last);

    hapusData(head, last, 52);
    hapusData(head, last, 42);
    cout << "" << endl;
    tampilkanFromHead(head);
    tampilkanFromLast(last);
}