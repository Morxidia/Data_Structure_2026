#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    // constructor untuk Node
    // Node(int value): data(value){}
};

Node *initQueue(int nilai)
{
    return new Node{nilai, nullptr};
}

void tampilkan(const Node *front)
{
    const Node *bantu = front;
    while (bantu != nullptr)
    {
        std::cout << bantu->data << ' ';
        bantu = bantu->next;
    }
    std::cout << '\n';
}

void enqueue(Node *&front, Node *&rear, int nilai)
{
    Node *baru = new Node{nilai, nullptr};
    if (front == nullptr && rear == nullptr)
    {
        front = baru;
        rear = baru;
        return;
    }
    else
    {
        rear->next = baru;
        rear = rear->next;
        // rear = baru
    }
}

Node *dequeue(Node *&front, Node *&rear)
{
    Node *dequeueVal = front;
    front = front->next;
    dequeueVal->next = nullptr;
    if (front == nullptr)
    {
        rear = nullptr;
    }
    return dequeueVal;
}

void clear(Node *&front)
{
    while (front != nullptr)
    {
        Node *hapus = front;
        front = front->next;
        delete hapus;
    }
}

int main(void)
{
    Node *front = nullptr;
    Node *rear = nullptr;

    enqueue(front, rear, 59);
    enqueue(front, rear, 26);
    enqueue(front, rear, 6);
    enqueue(front, rear, 30);
    tampilkan(front);
    cout << "data dequeu linked : " << (dequeue(front, rear))->data << endl;
    tampilkan(front);
}