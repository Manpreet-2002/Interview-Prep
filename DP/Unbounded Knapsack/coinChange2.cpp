#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> coin, int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                t[i][j] = 0;
            }
            if (i == 0)
            {
                t[i][j] = INT_MAX - 1;
            }
        }
    }
    for (int j = 1; j < sum + 1; j++)
    {
        if (j % coin[0] == 0)
        {
            t[1][j] = j / coin[0];
        }
        else
        {
            t[1][j] = INT_MAX - 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                t[i][j] = min(t[i][j - coin[i - 1]] + 1, t[i - 1][j]);
            }
            else if (coin[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> coin;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        coin.push_back(k);
    }
    int sum;
    cin >> sum;
    cout << knapsack(coin, sum, n);
    return 0;
}