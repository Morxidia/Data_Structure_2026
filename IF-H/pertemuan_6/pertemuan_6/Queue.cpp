#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;
int count = 0;

// 1. mengecek apakah queue kosong

bool isEmpty()
{
    return front == nullptr;
}

// 2. Menghitung Jumlah Data
int size()
{
    return count;
}

// 3. Menambahkan data (Enqueue)

void enqueue(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    count++;
    cout << value << " Berhasil Ditambahkan" << endl;
}

// 4. Menghapus data paling depan (Dequeue)
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Kosong " << endl;
        return;
    }

    Node *temp = front;
    cout << "Data Dihapus: " << temp->data << endl;

    front = front->next;

    if (front == nullptr)
    {
        rear = nullptr;
    }

    delete temp;
    count--;
}

// 5. Melihat data paling depan (peek)
void peekFront()
{
    if (isEmpty())
    {
        cout << "Queue Kosong" << endl;
    }
    else
    {
        cout << " Data Paling Depan: " << front->data << endl;
    }
}
// 6. Melihat data paling belakang (peek)
void peekRear()
{
    if (isEmpty())
    {
        cout << "Queue Kosong" << endl;
    }
    else
    {
        cout << " Data Paling Belakang: " << rear->data << endl;
    }
}

int main()
{
    enqueue(10);
    peekFront();
    enqueue(20);
    peekFront();
    peekRear();
    dequeue();
    peekFront();
}