

#include <iostream>
using namespace std;

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    // If the tree is empty, return a new node
    if (root == nullptr) { 
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}

// Function to do inorder traversal of BST
void inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorder(const Node* root) {
    if (root != nullptr){
        std::cout << root->data << ' ';
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(const Node* root) {
    if (root != nullptr){
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << ' ';
    }
}

// Function to search a given key in a given BST
Node* searchNode(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return searchNode(root->right, key);
    }

    // Key is smaller than root's key
    return searchNode(root->left, key);
}

// Function to find the inorder successor
Node* minValueNode(Node* node)
{
    Node* current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
Node* deleteNodeSuc(Node* root, int data)
{
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNodeSuc(root->left, data);
    }
    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNodeSuc(root->right, data);
    }
    // if data is same as root's data, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNodeSuc(root->right, temp->data);
    }
    return root;
}

// Helper function to find the node with maximum value (inorder predecessor)
Node* maxValueNode(Node* node)
{
    Node* current = node;
    while (current && current->right != nullptr)
        current = current->right;
    return current;
}

// Function to delete a node using inorder predecessor
Node* deleteNodePre(Node* root, int data)
{
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's data,
    // then it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNodePre(root->left, data);
    }
    // If the data to be deleted is greater than the root's data,
    // then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNodePre(root->right, data);
    }
    // If data is same as root's data, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder predecessor
        // (largest in the left subtree)
        Node* temp = maxValueNode(root->left);

        // Copy the inorder predecessor's content to this node
        root->data = temp->data;

        // Delete the inorder predecessor from the left subtree
        root->left = deleteNodePre(root->left, temp->data);
    }
    return root;
}

// Source - https://stackoverflow.com/a/51730733
// Posted by Adrian Schneider, modified by community. See post 'Timeline' for change history
// Retrieved 2026-10-22, License - CC BY-SA 4.0
// C++ Program to implement binary search tree
void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);    
}

int main()
{
    
    Node* root = nullptr;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    
    printBT(root);

    // Print the inorder traversal of a BST
    cout << "Inorder traversal of the given Binary Search "
    "Tree is: ";
    inorderTraversal(root);
    cout << endl;
    
    // delete a node in BST
    root = deleteNodePre(root, 20);
    cout << "After deletion of 20: ";
    inorderTraversal(root);
    cout << endl;
    
    // Insert a node in BST
    root = insertNode(root, 25);
    cout << "After insertion of 25: ";
    inorderTraversal(root);
    cout << endl;

    // Search a key in BST
    Node* found = searchNode(root, 25);

    // check if the key is found or not
    if (found != nullptr) {
        cout << "Node 25 found in the BST." << endl;
    }
    else {
        cout << "Node 25 not found in the BST." << endl;
    }

    return 0;
}
