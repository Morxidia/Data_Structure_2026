#include <iostream>
using namespace std;

const int cap = 4;

struct Queue
{
    int data[cap];
    int indFront = 0;
    int indRear = -1;
    int count = 0;
};

void initQueue(Queue &q)
{
    int data[cap];
    int indFront = 0;
    int indRear = -1;
    int count = 0;
}

bool isEmpty(Queue q)
{
    return q.count == 0;
}

bool isFull(Queue q)
{
    return q.count >= cap;
}

bool dequeu(Queue &q, int &nilaiKeluaran)
{
    if (isEmpty(q))
    {
        return false;
    }
    nilaiKeluaran = q.data[q.indFront];
    q.indFront = (q.indFront + 1) % cap;
    q.count--;
    return true;
}

bool enqueu(Queue &q, int nilaiMasuk)
{
    if (isFull(q))
    {
        return false;
    }
    q.indRear = (q.indRear + 1) % cap;
    q.data[q.indRear] = nilaiMasuk;
    q.count++;
    return true;
}

bool peek(const Queue &q, int &nilaiDepan)
{
    if (isEmpty(q))
        return false;
    nilaiDepan = q.data[q.indFront];
    return true;
}

void tampilkan(const Queue &q)
{
    if (isEmpty(q))
    {
        std::cout << "Queue kosong\n";
        return;
    }
    for (int i = 0; i < q.count; ++i)
    {
        int indeks = (q.indFront + i) % cap;
        std::cout << q.data[indeks] << ' ';
    }
    std::cout << '\n';
}

void clearQueue(Queue &q)
{
    initQueue(q);
}

void tampilkanArray(const Queue &q)
{
    if (isEmpty(q))
    {
        std::cout << "Queue kosong\n";
        return;
    }
    for (int i = 0; i < cap; ++i)
    {
        std::cout << q.data[i] << ' ';
    }
    std::cout << '\n';
}

int main(void)
{
    Queue q;
    initQueue(q);
    enqueu(q, 59);
    enqueu(q, 26);
    enqueu(q, 6);
    enqueu(q, 30);
    tampilkan(q);
    int temp{0};
    dequeu(q, temp);
    cout << "data deque : " << temp << endl;
    tampilkan(q);
}