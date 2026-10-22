#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    // constructor untuk Node
    // Node(int value): data(value){}
};

Node *buatNode(int nilai)
{
    return new Node{nilai, nullptr};
}

void tampilkan(const Node *head)
{
    const Node *bantu = head;
    while (bantu != nullptr)
    {
        std::cout << bantu->data << ' ';
        bantu = bantu->next;
    }
    std::cout << '\n';
}

void dequeue(Node *&head, int &nilai)
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    nilai = temp->data;
    delete temp;
    return;
}

void enqueue(Node *&head, int nilai)
{
    Node *baru = new Node{nilai, nullptr};
    if (head == nullptr)
    {
        head = baru;
        return;
    }

    Node *bantu = head;
    while (bantu->next != nullptr)
        bantu = bantu->next;

    bantu->next = baru;
}

void clear(Node *&head)
{
    while (head != nullptr)
    {
        Node *hapus = head;
        head = head->next;
        delete hapus;
    }
}

int main(void)
{
    int tempDataDeq{0};
    Node *head = nullptr;

    enqueue(head, 10);
    enqueue(head, 11);
    enqueue(head, 14);
    tampilkan(head);
    dequeue(head, tempDataDeq);
    cout << "Dequeue result : " << tempDataDeq << endl;
    enqueue(head, 17);
    tampilkan(head);
}