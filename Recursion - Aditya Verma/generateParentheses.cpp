#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string op, int k, int open, int close)
{
    if (open == k && close == k)
    {
        cout << op << endl;
        ans.push_back(op);
        return;
    }
    if (open < k)
    {
        string op1 = op;
        op1.push_back('{');
        solve(ans, op1, k, open + 1, close);
    }
    if (close < open)
    {
        string op2 = op;
        op2.push_back('}');
        solve(ans, op2, k, open, close + 1);
    }
    return;
}
int main()
{
    vector<string> ans;
    stack<char> s;
    solve(ans, "", 3, 0, 0);
    return 0;
}