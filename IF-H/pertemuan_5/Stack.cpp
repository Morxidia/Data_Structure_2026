#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedStack
{
    Node *top;
};

LinkedStack stack;

void buatStack()
{
    stack.top = nullptr;
}

bool isEmpty(LinkedStack &s)
{
    return s.top == nullptr;
}

bool push(LinkedStack &s, int nilai)
{
    Node *newNode = new Node;

    if (newNode == nullptr)
    {
        return false;
    }

    newNode->data = nilai;
    newNode->next = s.top;
    s.top = newNode;

    return true;
}

bool pop(LinkedStack &s, int &nilai)
{
    if (s.top == nullptr)
    {
        return false;
    }

    Node *temp = s.top;
    nilai = temp->data;
    s.top = s.top->next;

    delete temp;

    return true;
}

bool peek(LinkedStack &s, int &nilai)
{
    if (s.top == nullptr)
    {
        return false;
    }

    nilai = s.top->data;

    return true;
}

void tampilStack(LinkedStack stack)
{
    Node *current = stack.top;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    buatStack();

    push(stack, 10);
    push(stack, 30);
    push(stack, 20);

    cout << "Isi stack: ";
    tampilStack(stack);

    int nilai;

    if (peek(stack,nilai)){
        cout << "\n Nilai Top :" << nilai << endl;
    }

    if (pop(stack,nilai)){
        cout << "Data yang di pop " << nilai << endl;

    }

    cout << "Isi stack setelah pop :";
    tampilStack(stack);

    
    return 0;
}
