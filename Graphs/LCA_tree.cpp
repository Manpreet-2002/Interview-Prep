#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void dfs(TreeNode *root, int x, vector<int> &res, bool &find)
{
    if (find)
    {
        return;
    }
    if (root == NULL)
    {
        return;
    }
    if (root->val == x)
    {
        res.push_back(x);
        find = true;
        return;
    }
    dfs(root->left, x, res, find);
    dfs(root->right, x, res, find);
    if (find)
    {
        res.push_back(root->val);
        return;
    }
    return;
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
    vector<int> path;
    bool one = false;
    dfs(root, 3, path, one);
    for (int num : path)
    {
        cout << num << endl;
    }
    return 0;
}