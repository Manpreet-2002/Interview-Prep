#include <bits/stdc++.h>
using namespace std;

string func(string x, string y)
{
    int n = x.length();
    int m = y.length();
    string t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = "";
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = t[i - 1][j - 1];
                t[i][j].push_back(x[i - 1]);
            }
            else
            {
                int size1 = t[i - 1][j].size();
                int size2 = t[i][j - 1].size();
                if (size1 > size2)
                {
                    t[i][j] = t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i][j - 1];
                }
                // t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][m];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x, y;
    cin >> x;
    cin >> y;
    cout << func(x, y) << endl;
}