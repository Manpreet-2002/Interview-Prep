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
vector<int> itrPreOrder(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> preOrder;
    if (root == NULL)
    {
        return preOrder;
    }
    st.push(root);
    while (!st.empty())
    {
        cout << st.top()->data << " ";
        TreeNode *popped = st.top();
        preOrder.push_back(popped->data);
        st.pop();
        if (popped->right != NULL)
        {
            st.push(popped->right);
        }
        if (popped->left != NULL)
        {
            st.push(popped->left);
        }
    }
    return preOrder;
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
    itrPreOrder(root);
}