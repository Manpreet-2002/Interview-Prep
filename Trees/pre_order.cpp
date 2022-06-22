#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void preOrder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
    return;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(12);
    preOrder(root);
}