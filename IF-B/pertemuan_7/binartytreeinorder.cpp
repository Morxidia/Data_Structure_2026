#include <iostream>
using namespace std;

// Inorder (Left -> Root -> Right)

struct Node
{
    char data;
    Node *left;
    Node *right;
};

struct Queue
{
    Node **data;
    int front;
    int rear;
    int count;
    const int size;

    Queue(const int size) : data(new Node *[size]), front(0), rear(-1), count(0), size(size) {};

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }

    bool enqueue(Node *nilai)
    {
        if (isFull())
            return false;

        rear = (rear + 1) % size;
        data[rear] = nilai;
        ++count;
        return true;
    }

    bool dequeue(Node *&nilaiKeluar)
    {
        if (isEmpty())
            return false;

        nilaiKeluar = data[front];
        front = (front + 1) % size;
        --count;
        return true;
    }

    ~Queue()
    {
        delete[] data;
    }
};

Node *buatNode(char data)
{
    Node *baru = new Node;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void levelOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    Queue pq(20);
    pq.enqueue(root);

    while (!pq.isEmpty())
    {
        Node *temp;
        pq.dequeue(temp);
        if (temp->left != nullptr)
        {
            pq.enqueue(temp->left);
        }
        if (temp->right != nullptr)
        {
            pq.enqueue(temp->right);
        }
        cout << temp->data << " ";
    }
}

void printBT(const std::string &prefix, const Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node *node)
{
    printBT("", node, false);
}

int main()
{
    Node *root = buatNode('A');

    root->left = buatNode('B');
    root->right = buatNode('C');

    root->left->left = buatNode('D');
    root->left->right = buatNode('E');

    root->right->left = buatNode('F');
    root->right->right = buatNode('G');

    printBT(root);
    cout << "Binary Tree Inorder: ";
    levelOrder(root);

    cout << endl;
    return 0;
}