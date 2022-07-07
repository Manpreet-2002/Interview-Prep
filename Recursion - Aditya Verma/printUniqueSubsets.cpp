#include <bits/stdc++.h>
using namespace std;

void solve(string op, string ip, set<string> &s)
{
    if (ip.length() == 0)
    {
        if (!s.count(op))
            cout << op << endl;
        s.insert(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(op1, ip, s);
    solve(op2, ip, s);
    return;
}
int main()
{
    set<string> s;
    string str = "aab";
    solve("", str, s);
    return 0;
}
