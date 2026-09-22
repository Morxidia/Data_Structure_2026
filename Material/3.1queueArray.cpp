#include <iostream>
using namespace std;

const int KAPASITAS = 5;

struct Queue {
    int data[KAPASITAS];
    int front;
    int rear;
    int count;
};

void init(Queue& q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isEmpty(const Queue& q) {
    return q.count == 0;
}

bool isFull(const Queue& q) {
    return q.count == KAPASITAS;
}

bool enqueue(Queue& q, int nilai) {
    if (isFull(q)) return false;
    q.rear = (q.rear + 1) % KAPASITAS;
    q.data[q.rear] = nilai;
    ++q.count;
    return true;
}

bool dequeue(Queue& q, int& nilaiKeluar) {
    if (isEmpty(q)) return false;
    nilaiKeluar = q.data[q.front];
    q.front = (q.front + 1) % KAPASITAS;
    --q.count;
    return true;
}

bool peek(const Queue& q, int& nilaiDepan) {
    if (isEmpty(q)) return false;
    nilaiDepan = q.data[q.front];
    return true;
}

void tampilkan(const Queue& q) {
    if (isEmpty(q)) {
        std::cout << "Queue kosong\n";
        return;
    }
    for (int i = 0; i < q.count; ++i) {
        int indeks = (q.front + i) % KAPASITAS;
        std::cout << q.data[indeks] << ' ';
    }
    std::cout << '\n';
}

void clear(Queue& q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}