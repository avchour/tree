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

    Tree() {
        root = nullptr;
    }
};


int main() {
    Tree tree;
    return 0;
}