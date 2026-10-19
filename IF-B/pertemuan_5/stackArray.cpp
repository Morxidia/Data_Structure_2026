#include <iostream>
using namespace std;

struct element
{
    int data;
};

struct StackElement
{
    element *data;
    int size;
    int topIndex;
};

StackElement *initStack(int size)
{
    StackElement *stack = new StackElement;
    stack->data = new element[size];
    stack->size = size;
    stack->topIndex = -1;
    return stack;
}

bool isFull(StackElement *&stack)
{
    return stack->topIndex >= (stack->size - 1);
}

bool isEmpty(StackElement *&stack)
{
    return stack->topIndex == -1;
}

bool push(StackElement *&stack, element input)
{
    if (isFull(stack))
    {
        return false;
    }
    stack->data[++stack->topIndex] = input;
    return true;
}

bool pop(StackElement *&stack, element &output)
{
    if (isEmpty(stack))
    {
        output = element();
        return false;
    }
    output = stack->data[stack->topIndex--];
    return true;
}

void tampilStack(StackElement *stack)
{
    if (isEmpty(stack))
    {
        cout << "stack kosong" << endl;
        return;
    }
    cout << "stack : ";
    for (int i = stack->topIndex; i >= 0; i--)
    {
        cout << stack->data[i].data << " - ";
    }
    cout << " end of stack " << endl;
}

void peek(StackElement *stack)
{
    if (isEmpty(stack))
    {
        cout << "stack kosong" << endl;
        return;
    }
    cout << "top : " << stack->data[stack->topIndex].data << endl;
}

int main()
{
    StackElement *stack = initStack(2);
    element el = element{5};
    push(stack, el);
    el.data = 10;
    push(stack, el);
    el.data = 7;
    push(stack, el);
    el.data = 11;
    push(stack, el);
    tampilStack(stack);
    peek(stack);
    pop(stack, el);
    tampilStack(stack);
    peek(stack);
    pop(stack, el);
    tampilStack(stack);
}
