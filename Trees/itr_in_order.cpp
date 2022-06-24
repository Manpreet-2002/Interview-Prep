#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        data = 0;
        left = right = NULL;
    }
    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
    TreeNode(int val, TreeNode *_left, TreeNode *_right)
    {
        data = val;
        left = _left;
        right = _right;
    }
};
vector<int> itrInOrder(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> inOrder;
    if (root == NULL)
    {
        return inOrder;
    }
    TreeNode *node = root;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            node = st.top();
            cout << node->data << " ";
            inOrder.push_back(node->data);
            st.pop();
            node = node->right;
        }
    }
    return inOrder;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(12);
    itrInOrder(root);
}