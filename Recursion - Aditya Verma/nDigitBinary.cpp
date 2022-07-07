#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string op, int k, int ones, int zeroes)
{
    if (op.size() == k)
    {
        cout << op << endl;
        ans.push_back(op);
        return;
    }
    if (ones < k)
    {
        string op1 = op;
        op1.push_back('1');
        solve(ans, op1, k, ones + 1, zeroes);
    }
    if (zeroes < ones)
    {
        string op2 = op;
        op2.push_back('0');
        solve(ans, op2, k, ones, zeroes + 1);
    }
    return;
}
int main()
{
    vector<string> ans;
    solve(ans, "", 5, 0, 0);
    return 0;
}