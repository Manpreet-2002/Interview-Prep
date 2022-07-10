#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][w];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> wt;
    wt.push_back(1);
    wt.push_back(3);
    wt.push_back(4);
    wt.push_back(5);
    vector<int> val;
    val.push_back(1);
    val.push_back(4);
    val.push_back(5);
    val.push_back(7);
    int w = 7;
    cout << knapsack(wt, val, w, 4);
    return 0;
}