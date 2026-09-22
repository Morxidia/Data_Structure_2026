#include <iostream>
using namespace std;
/*
*   hasil perubahan strucktur Queue by Morxidia
*/

struct Queue {
    int* data;
    int front;
    int rear;
    int count;
    const int size;

    Queue(const int size):data(new int[size]), front(0), rear(-1), count(0), size(size){};

    ~Queue(){
        delete[] data;
    }
};

bool isEmpty(const Queue& q) {
    return q.count == 0;
}

bool isFull(const Queue& q) {
    return q.count == q.size;
}

bool enqueue(Queue& q, int nilai) {
    if (isFull(q)) 
        return false;

    q.rear = (q.rear + 1) % q.size;
    q.data[q.rear] = nilai;
    ++q.count;
    return true;
}

bool dequeue(Queue& q, int& nilaiKeluar) {
    if (isEmpty(q))
        return false;
        
    nilaiKeluar = q.data[q.front];
    q.front = (q.front + 1) % q.size;
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
        int indeks = (q.front + i) % q.size;
        std::cout << q.data[indeks] << ' ';
    }
    std::cout << '\n';
}

void clear(Queue& q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
    delete[] q.data;
}