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
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
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
    vector<int> wt;
    wt = {12, 7, 12, 10, 41, 41, 1, 6, 30, 20, 9, 35, 9, 11, 32, 24, 42, 48, 37, 36};
    vector<int> val;
    val = {32, 18, 24, 48, 14, 5, 29, 47, 13, 41, 48, 30, 45, 20, 13, 44, 1, 10, 9, 20};
    int w = 300;
    cout << knapsack(wt, val, w, 20);
    return 0;
}