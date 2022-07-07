#include <bits/stdc++.h>
using namespace std;

void solve(string op, string ip)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    if (ip.length() > 1)
    {
        op2.push_back(ip[0]);
        op2.append(" ");
    }
    op1.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(op1, ip);
    if (ip.length() >= 1)
        solve(op2, ip);
}
int main()
{
    string str = "ABC";
    solve("", str);
    return 0;
}