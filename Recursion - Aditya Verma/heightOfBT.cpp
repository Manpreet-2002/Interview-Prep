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

int height(Node *root)
{
    if (!root->left && !root->right)
    {
        return 1;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}