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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// void ReverseOrderTraversal(node *root)
// {
//     stack<node *> s;
//     queue<node *> q;
//     q.push(root);

//     while (q.empty() == false)
//     {
//         // dequeu node and make it root
//         root = q.front();
//         q.pop();
//         s.push(root);
//     }
//     // enqueur right child
//     if (root->right)
//         q.push(root->right);
//     if (root->left)
//         q.push(root->left);
//     // now all pop all items form stack one by one and print tem
//     while (s.empty() == false)
//     {
//         root = s.top();
//         cout << root->data << "";
//         s.pop();
//     }
// }
void inorder(node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
void postOrder(node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void *buildFromLevelOrde(node *root)
{
    queue<node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter lefe node for" << root->left;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter teh right node " << root->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    // CREATing a tree
    root = buildTree(root);
    // level order travserssal
    cout << "printing the level order traversal output" << endl;
    levelOrderTraversal(root);
    // cout << "printing the reverse order traversal output" << endl;
    // ReverseOrderTraversal(root);
    cout << "inorder traversal" << endl;
    inorder(root);
    cout << "preorder order traversal" << endl;
    preorder(root);
    cout << "postorder order traversal" << endl;
    postOrder(root);
    return 0;
}