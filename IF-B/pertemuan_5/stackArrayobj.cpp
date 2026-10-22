#include <iostream>
using namespace std;

struct element
{
    int data;
};

struct StackElement
{
    element *data;
    const int size;
    int topIndex;

    StackElement(int size) : data(new element[size]), size(size), topIndex(-1) {};

    bool isFull()
    {
        return topIndex >= (size - 1);
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool push(element input)
    {
        if (isFull())
        {
            return false;
        }
        data[++topIndex] = input;
        return true;
    }

    bool pop(element &output)
    {
        if (isEmpty())
        {
            output = element();
            return false;
        }
        output = data[topIndex--];
        return true;
    }

    void tampilStack()
    {
        if (isEmpty())
        {
            cout << "stack kosong" << endl;
            return;
        }
        cout << "stack : ";
        for (int i = topIndex; i >= 0; i--)
        {
            cout << data[i].data << " - ";
        }
        cout << " end of stack " << endl;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "stack kosong" << endl;
            return;
        }
        cout << "top : " << data[topIndex].data << endl;
    }
};

int main()
{
    StackElement stack = StackElement(2);
    element el = element{5};
    stack.push(el);
    el.data = 10;
    stack.push(el);
    el.data = 7;
    stack.push(el);
    el.data = 11;
    stack.push(el);
    stack.tampilStack();
    stack.peek();
    stack.pop(el);
    stack.tampilStack();
    stack.peek();
    stack.pop(el);
    stack.tampilStack();
}
