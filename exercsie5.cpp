
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node
{
public:
    int citizenID;
    Node *left;
    Node *right;

    Node(int citizenID)
    {
        this->citizenID = citizenID;
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
    Node *insert(Node *root, int citizenID)
    {
        if (root == nullptr)
        {
            root = new Node(citizenID);
        }
        else if (citizenID < root->citizenID)
        {
            root->left = insert(root->left, citizenID);
        }
        else if (citizenID > root->citizenID)
        {
            root->right = insert(root->right, citizenID);
        }

        return root;
    }

    void insert(int citizenID)
    {
        root = insert(root, citizenID);
    }

    // (DLR) Pre-order
    void preOrder(Node *root, ofstream &file)
    {
        if (root == nullptr)
            return;

        file << root->citizenID << endl;
        preOrder(root->left, file);
        preOrder(root->right, file);
    }

    // (LDR) In-order
    void inOrder(Node *root, ofstream &file)
    {
        if (root == nullptr)
            return;

        inOrder(root->left, file);
        file << root->citizenID << endl;
        inOrder(root->right, file);
    }

    // (LRD) Post-order
    void postOrder(Node *root, ofstream &file)
    {
        if (root == nullptr)
            return;

        postOrder(root->left, file);
        postOrder(root->right, file);
        file << root->citizenID << endl;
    }

    // Recursive search
    Node *search(Node *root, int citizenID)
    {
        if (root == nullptr)
            return nullptr;

        else if (citizenID == root->citizenID)
            return root;

        else if (citizenID < root->citizenID)
            return search(root->left, citizenID);

        else
            return search(root->right, citizenID);
    }

    // Public search
    Node *search(int citizenID)
    {
        return search(root, citizenID);
    }
};

// Generate CSV file
void generateCSV()
{
    srand(time(0));

    ofstream myfile("data.csv");

    if (!myfile.is_open())
    {
        cout << "Cannot create file!" << endl;
        return;
    }

    for (int i = 1; i <= 1000000; i++)
    {
        int id = rand() % 1000000000 + 1;
        myfile << id << endl;
    }

    myfile.close();

    cout << "CSV file generated!" << endl;
}

// Read CSV and insert into BST
void loadCSV(Tree &tree)
{
    ifstream myfile("data.csv");

    if (!myfile.is_open())
    {
        cout << "Cannot open file!" << endl;
        return;
    }

    int id;
    int count = 0;

    while (myfile >> id)
    {
        tree.insert(id);
        count++;
    }

    myfile.close();

    cout << count << " IDs read from CSV." << endl;
}

// Save traversal results
void saveTraversal(Tree &tree)
{
    ofstream preFile("preorder.txt");
    ofstream inFile("inorder.txt");
    ofstream postFile("postorder.txt");

    if (!preFile.is_open() ||
        !inFile.is_open() ||
        !postFile.is_open())
    {
        cout << "Cannot create traversal files!" << endl;
        return;
    }

    tree.preOrder(tree.root, preFile);
    tree.inOrder(tree.root, inFile);
    tree.postOrder(tree.root, postFile);

    preFile.close();
    inFile.close();
    postFile.close();

    cout << "Traversal files saved!" << endl;
}

int main()
{
    Tree tree;

       generateCSV();

    loadCSV(tree);

    saveTraversal(tree);

    int id;

    while (true)
    {
        cout << "Enter Citizen ID : ";
        cin >> id;

        if (id == 0)
        {
            cout << "Program is not store with 0" << endl;
            break;
        }

        Node *result = tree.search(id);

        if (result != nullptr)
        {
            cout << "Citizen ID exists in BST!" << endl;
            cout << "ID: " << result->citizenID << endl;
        }
        else
        {
            cout << "Citizen ID not found!" << endl;
        }
    }

    return 0;
}
