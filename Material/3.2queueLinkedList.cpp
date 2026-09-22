#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedQueue {
    Node* front;
    Node* rear;
};

bool enqueue(LinkedQueue& q, int nilai) {
    Node* baru = new Node{nilai, nullptr};
    if (q.rear == nullptr) q.front = q.rear = baru;
    else {
        q.rear->next = baru;
        q.rear = baru;
    }
    return true;
}

bool dequeue(LinkedQueue& q, int& nilaiKeluar) {
    if (q.front == nullptr) return false;
    Node* hapus = q.front;
    nilaiKeluar = hapus->data;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete hapus;
    return true;
}
