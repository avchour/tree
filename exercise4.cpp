#include <iostream>
using namespace std;

class Node
{
public:
    int productID;
    string productName;
    Node *left;
    Node *right;

    Node(int productID, string productName)
    {
        this->productID = productID;
        this->productName = productName;
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

    Node *insert(Node *root, int productID, string productName)
    {
        if (root == nullptr)
        {
            root = new Node(productID, productName);
        }
        else if (productID > root->productID)
        {
            root->right = insert(root->right, productID, productName);
        }
        else if (productID < root->productID)
        {
            root->left = insert(root->left, productID, productName);
        }

        return root;
    }

    void insert(int productID, string productName)
    {
        root = insert(root, productID, productName);
    }

    Node *search(Node *root, int productID)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (productID == root->productID)
        {
            return root;
        }
        else if (productID < root->productID)
        {
            return search(root->left, productID);
        }
        else
        {
            return search(root->right, productID);
        }
    }

    Node *search(int productId)
    {
        return search(root, productId);
    }

    // display order
    void inOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left);
        cout << "ID :" << root->productID << " Name: " << root->productName << endl;
        inOrder(root->right);
    }
};

int main()
{
    Tree products;

    products.insert(50, "Wireless Mouse");
    products.insert(30, "Mechanical Keyboard");
    products.insert(70, "USB-C Hub");
    products.insert(20, "Mouse Pad");
    products.insert(60, "Webcam HD");
    products.inOrder(products.root);

    int id;
    cout << "\nEnter Product ID: ";
    cin >> id;

    Node *result = products.search(id);

    if (result != nullptr)
    {
        cout << "\nProduct Found!" << endl;
        cout << "ID: " << result->productID << endl;
        cout << "Name: " << result->productName << endl;
    }
    else
    {
        cout << "\nProduct not found!" << endl;
        
    }

    return 0;
}
