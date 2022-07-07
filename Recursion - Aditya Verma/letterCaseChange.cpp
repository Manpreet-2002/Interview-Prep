#include <bits/stdc++.h>
using namespace std;

void solve(string op, string ip)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin() + 0);
        solve(op1, ip);
        solve(op2, ip);
    }
    else
    {
        op.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        solve(op, ip);
    }
    return;
}
int main()
{
    string s = "a1B2";
    solve("", s);
    return 0;
}