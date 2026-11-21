#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;

    Node(string name)
    {
        this->name = name;
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

    Node *insert(Node *root, string name)
    {
        if (root == nullptr)
        {
            root = new Node(name);
        }
        else if (name < root->name)
        {
            root->left = insert(root->left, name);
        }
        else if (name > root->name)
        {
            root->right = insert(root->right, name);
        }

        return root;
    }

    void insert(string name)
    {
        root = insert(root, name);
    }

    // In-order traversal (LDR)
    void inOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
        cout << root->name << endl;
        inOrder(root->right);
    }
};

int main()
{
    Tree students;

    // Insert student names
    students.insert("Sokha");
    students.insert("Dara");
    students.insert("Vanna");
    students.insert("Bopha");
    students.insert("Mony");
    students.insert("Chan");
    students.insert("Sovann");
    students.insert("Kanha");

    // Display student names alphabetically
    cout << "Student Names (A-Z):" << endl;
    students.inOrder(students.root);

    return 0;
}