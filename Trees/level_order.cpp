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
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == NULL)
    {
        return res;
    }
    queue<TreeNode *> store;
    store.push(root);
    while (!store.empty())
    {
        int size = store.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = store.front();
            store.pop();
            if (node->left != NULL)
            {
                store.push(node->left);
            }
            if (node->right != NULL)
            {
                store.push(node->right);
            }
            level.push_back(node->data);
        }
        res.push_back(level);
    }
    return res;
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
    vector<vector<int>> ans = levelOrder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
}