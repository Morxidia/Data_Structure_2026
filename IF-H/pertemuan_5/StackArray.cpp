#include <iostream>
using namespace std;

struct TipeData
{
    int data;
};

struct Stack
{
    TipeData *dataStack;
    int size;
    int topIndex;
};

Stack *initStack(int size)
{
    Stack *stackbaru = new Stack;
    stackbaru->dataStack = new TipeData[size];
    stackbaru->size = size;
    stackbaru->topIndex = -1;
    return stackbaru;
}

bool isFull(Stack *&stack)
{
    return stack->topIndex >= stack->size - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->topIndex < 0;
}

bool push(Stack *&stack, TipeData input)
{
    if (isFull(stack))
    {
        return false;
    }
    else
    {
        // stack->dataStack = stack->dataStack + 1;
        stack->dataStack[++stack->topIndex] = input;
        return true;
    }
}

bool pop(Stack *&stack, TipeData &output)
{
    if (isEmpty(stack))
    {
        output = TipeData{-67};
        return false;
    }
    else
    {
        output = stack->dataStack[stack->topIndex--];
        // stack->topIndex = stack->topIndex -1;
        return true;
    }
}

void peek(Stack *&stack)
{
    if (isEmpty(stack))
    {
        cout << "stack kosong" << endl;
    }
    else
    {
        cout << "top : " << stack->dataStack[stack->topIndex].data << endl;
    }
}

void tampilStack(Stack *&stack)
{
    if (isEmpty(stack))
    {
        cout << "stack kosong" << endl;
    }
    else
    {
        cout << "Stack : ";
        for (int i = stack->topIndex; i >= 0; i--)
        {
            cout << stack->dataStack[i].data << " - ";
        }
        cout << "end of stack" << endl;
    }
}

int main(void)
{
    Stack *stack = initStack(90);
    TipeData temp = TipeData{0};
    push(stack, TipeData{5});
    tampilStack(stack);
    push(stack, TipeData{15});
    tampilStack(stack);
    push(stack, TipeData{31});
    tampilStack(stack);
    push(stack, TipeData{25});
    tampilStack(stack);
    cout << "ambil - ";
    peek(stack);
    pop(stack, temp);
    cout << temp.data << " -- nilai ini telah diambil" << endl;
    tampilStack(stack);
    cout << "ambil - ";
    peek(stack);
    pop(stack, temp);
    cout << temp.data << " -- nilai ini telah diambil" << endl;
    tampilStack(stack);
    cout << "ambil - ";
    peek(stack);
    pop(stack, temp);
    cout << temp.data << " -- nilai ini telah diambil" << endl;
    tampilStack(stack);
    cout << "ambil - ";
    peek(stack);
    pop(stack, temp);
    cout << temp.data << " -- nilai ini telah diambil" << endl;
    tampilStack(stack);
}