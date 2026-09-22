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
    // initialization for the Node first time in heap memory
    Node *newNode = new Node{nilai, nullptr, nullptr};
    return newNode;
}

void tampilkanFromHead(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            cout << " <-> ";
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
void tampilkanFromLast(Node *last)
{
    Node *current = last;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->prev != nullptr)
        {
            cout << " <-> ";
            current = current->prev;
        }
        else
        {
            cout << " -- end of data" << endl;
            return;
        }
    }
    return;
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
        return true;
    }

    // sisip depan
    if (head->data >= nilai)
    {
        // newnode next-> head, head prev-> newNode
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return true;
    };

    // 10 11 15
    // 13
    // temp 11 next 15

    Node *current = head;
    while (current->next != nullptr && current->next->data < nilai)
    {
        current = current->next;
    }

    if (current->next != nullptr)
    {
        newNode->next = current->next;
        // depan sambung new
        current->next->prev = newNode;
        current->next = newNode;

        // current sambung new
        newNode->prev = current;
        return true;
    }
    else if (current->next == nullptr)
    {
        // sisip belakang
        newNode->prev = current;
        current->next = newNode;
        // perubahan variable last itu diakhir
        last = newNode;
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

bool hapusData(Node *&head, Node *&last, int nilai)
{
    if (head == nullptr)
    {
        // check if the list is empty
        return false;
    }
    Node *current = head;
    while (current->next != nullptr && current->data != nilai)
    {
        current = current->next;
    }

    if (current->data == nilai){
        if (current == head)
        {
            // hapus depan
            head = current->next;
            if(head != nullptr){
                // hapus depan jika list berisi lebih satu node
                head->prev = nullptr;
            }else{
                // hapus depan jika list berisi satu node
                last = nullptr;
            }
        }
        else if (current->next != nullptr)
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
            last->next = nullptr;
        }
        delete current;
        return true;
    }
    return false;
}

void clear(Node *&head, Node *&last)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *berikut = current->next; 
        delete current;                
        current = berikut;             
    }
    
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
    tampilkanFromHead(head);
    tampilkanFromLast(last);
}