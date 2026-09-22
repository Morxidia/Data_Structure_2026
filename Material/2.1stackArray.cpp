#include <iostream>
using namespace std;

struct Node{
    int data;
};

struct Stack{
    Node* data;
    int top;
    const int size;
};

Stack* initializeStack(const int size){
    return new Stack{new Node[size], -1, size};
}

bool stackPush(Stack*& stack, Node input){
    if(stack->top >= stack->size - 1){
        return false;
    }
    stack->data[++stack->top] = input;
    return true;
}

Node stackPop(Stack*& stack){
    if(stack->top < 0){
        cerr << "Stack Underflow!\n";
        return Node{-1};
    }
    return stack->data[stack->top--];
}

void tampilkanStack(Stack* stack) {
    if (stack->top < 0) {
        cerr << "Stack Kosong\n";
        return;
    }
    cout << "Isi Stack (Top -> Bottom): ";
    for (int i = stack->top; i >= 0; i--) {
        cout << stack->data[i].data << " ";
    }
    cout << endl;
}

bool clearStack(Stack*& stack){
    if (stack != nullptr) {
        delete[] stack->data; 
        delete stack;  
        stack = nullptr;
        return true;
    }
    else{
        return false;
    }
}

int main(void){
const int size = 10;
    int top = -1;
    Stack* stack = initializeStack(size);

    stackPush(stack, Node{1});
    stackPush(stack, Node{4});
    stackPush(stack, Node{2});

    tampilkanStack(stack); 

    Node popped = stackPop(stack);
    cout << "Data yang di-pop: " << popped.data << endl; 

    tampilkanStack(stack); 
  
    clearStack(stack);
    return 0;
}