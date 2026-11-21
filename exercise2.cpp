
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = nullptr;
    }

    // Recursive insertion
    Node *insert(Node *root, int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
        }
        else if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }

        return root;
    }

    // Public insert function
    void insert(int data)
    {
        root = insert(root, data);
    }

    // (LDR) Left Data Right
    void inOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    // (LRD) Left Right Data
    void postOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    // (DLR) Data Left Right
    void preOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main()
{
    Tree tree;

    tree.insert(50);
    tree.insert(17);
    tree.insert(72);
    tree.insert(12);
    tree.insert(23);
    tree.insert(54);
    tree.insert(76);
    tree.insert(9);
    tree.insert(14);
    tree.insert(19);
    tree.insert(67);

    cout << "In-order: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Post-order: ";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "Pre-order: ";
    tree.preOrder(tree.root);
    cout << endl;

    return 0;
}
