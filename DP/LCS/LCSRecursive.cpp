#include <bits/stdc++.h>
using namespace std;

int func(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    char s1 = x[n - 1];
    char s2 = y[m - 1];
    if (s1 == s2)
    {
        return func(x, y, n - 1, m - 1) + 1;
    }
    else
    {
        return max(func(x, y, n, m - 1), func(x, y, n - 1, m));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x, y;
    cin >> x;
    cin >> y;
    cout << func(x, y, x.length(), y.length()) << endl;
}