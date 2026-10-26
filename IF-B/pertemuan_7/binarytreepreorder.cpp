#include <iostream>
using namespace std;

// Preorder (Root -> Left -> Right)

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *buatNode(char data)
{
    Node *baru = new Node;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
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
    postOrder(root);

    cout << endl;
    return 0;
}
