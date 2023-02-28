#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "Enter the data for node" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    // making left and right leaf
    cout << "Enter data for inserting in left" << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right" << endl;
    root->right = buildTree(root->right);
    return root;
}

void preorder(node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root = NULL;
    // CREATing a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    cout << "Preorder traversal" << endl;
    preorder(root);

    return 0;
}