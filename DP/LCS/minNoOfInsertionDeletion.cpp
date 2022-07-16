#include <bits/stdc++.h>
using namespace std;

pair<int, int> func(string x, string y)
{
    int n = x.length();
    int m = y.length();
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1] + 1;
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return {n - t[n][m], m - t[n][m]};
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x, y;
    cin >> x;
    cin >> y;
    cout << func(x, y).first << " " << func(x, y).second << endl;
}