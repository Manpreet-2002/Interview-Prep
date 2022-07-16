#include <bits/stdc++.h>
using namespace std;

int static t[7][8];

int func(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (t[n][m] != -1)
    {
        return t[n][m];
    }
    char s1 = x[n - 1];
    char s2 = y[m - 1];
    if (s1 == s2)
    {
        return t[n][m] = func(x, y, n - 1, m - 1) + 1;
    }
    else
    {
        return t[n][m] = max(func(x, y, n, m - 1), func(x, y, n - 1, m));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x, y;
    cin >> x;
    cin >> y;
    memset(t, -1, sizeof(t));
    cout << func(x, y, x.length(), y.length()) << endl;
}