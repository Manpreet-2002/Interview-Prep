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
    op1.push_back(ip[0]);
    char upper = (char)toupper(ip[0]);
    op2.push_back(upper);
    ip.erase(ip.begin() + 0);
    solve(op1, ip);
    solve(op2, ip);
    return;
}
int main()
{
    string s = "ab";
    solve("", s);
    return 0;
}