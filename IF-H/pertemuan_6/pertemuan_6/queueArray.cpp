#include <iostream>
using namespace std;

const int kapasitas{3};

struct Queue
{
    int data[kapasitas];
    int indFront;
    int indRear;
    int count;
};

void initQueueu(Queue &q)
{
    q.indFront = 0;
    q.indRear = -1;
    q.count = 0;
}

bool isFull(const Queue &q)
{
    return q.count >= kapasitas;
}

bool isEmpty(const Queue &q)
{
    return q.count <= 0;
}

bool enqueue(Queue &q, int value)
{
    if (!isFull(q))
    {
        q.indRear = (q.indRear + 1) % kapasitas;
        q.data[q.indRear] = value;
        q.count++;
        return true;
    }
    return false;
}

bool dequeu(Queue &q, int &nilaiKeluaran)
{
    if (!isEmpty(q))
    {
        nilaiKeluaran = q.data[q.indFront];
        q.indFront = (q.indFront + 1) % kapasitas;
        q.count--;
        return true;
    }
    return false;
}

bool peek(const Queue &q, int &nilaiKeluaran)
{
    if (!isEmpty(q))
    {
        nilaiKeluaran = q.data[q.indFront];
        return true;
    }
    return false;
}

void tampilQueue(const Queue &q)
{
    if (!isEmpty(q))
    {
        for (int i = 0; i < q.count; i++)
        {
            int indCurr = (q.indFront + i) % kapasitas;
            cout << q.data[indCurr] << " ";
        }
        cout << endl;
        return;
    }
}

void tampilQueueUrut(const Queue &q)
{
    if (!isEmpty(q))
    {
        for (int i = 0; i < kapasitas; i++)
        {
            cout << q.data[i] << " ";
        }
        cout << endl;
        return;
    }
}

int main()
{
    int tempDataDeq;
    Queue q;
    initQueueu(q);
    enqueue(q, 10);
    enqueue(q, 13);
    enqueue(q, 17);
    enqueue(q, 12);
    tampilQueue(q);
    dequeu(q, tempDataDeq);
    cout << "Dequeue result : " << tempDataDeq << endl;
    enqueue(q, 19);
    tampilQueue(q);
}
