#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *buatNode(int nilai)
{
    Node *nodebaru = new Node;
    nodebaru->data = nilai;
    nodebaru->next = nullptr;
    return nodebaru;
}

bool isEmpty(Node *&top)
{
    return top == nullptr;
}

bool push(Node *&top, int nilai)
{
    Node *nodebaru = buatNode(nilai);
    nodebaru->next = top;
    top = nodebaru;
    return true;
}

bool pop(Node *&top, Node *&refAmbil)
{
    if (isEmpty(top))
    {
        refAmbil = nullptr;
        return false;
    }
    Node *nodeAmbil = top;
    top = top->next;
    nodeAmbil->next = nullptr;
    refAmbil = nodeAmbil;
    return true;
}

void peek(Node *&top)
{
    if (isEmpty(top))
    {
        cout << "stack kosong" << endl;
        return;
    }
    cout << "Top data : " << top->data << endl;
}

void tampilStack(Node *top)
{
    if (isEmpty(top))
    {
        cout << "stack kosong" << endl;
        return;
    }
    Node *current = top;
    cout << "Stack" << endl;
    do
    {
        cout << current->data << endl;
        current = current->next;
    } while (current != nullptr);
    cout << "end of stack" << endl;
    return;
}

int main(void)
{
    Node *top = nullptr;
    Node *refAmbil = nullptr;
    push(top, 10);
    tampilStack(top);
    push(top, 4);
    tampilStack(top);
    push(top, 1);
    tampilStack(top);
    pop(top, refAmbil);
    int data = 0;
    cout << "data diambil : " << refAmbil->data << endl;
    delete refAmbil;
    refAmbil = nullptr;
    pop(top, refAmbil);
    cout << "data diambil : " << refAmbil->data << endl;
    delete refAmbil;
    refAmbil = nullptr;
    pop(top, refAmbil);
    data = refAmbil == nullptr ? -1 : refAmbil->data;
    cout << "data diambil : " << data << endl;
    delete refAmbil;
    refAmbil = nullptr;
    pop(top, refAmbil);
    data = refAmbil == nullptr ? -1 : refAmbil->data;
    cout << "data diambil : " << data << endl;
    delete refAmbil;
    refAmbil = nullptr;
    tampilStack(top);
}