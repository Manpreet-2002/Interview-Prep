#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int static t[5][8];

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (t[n][w] != -1)
    {
        return t[n][w];
    }
    if (wt[n - 1] <= w)
    {
        t[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
        return t[n][w];
    }
    else if (wt[n - 1] > w)
    {
        t[n][w] = knapsack(wt, val, w, n - 1);
        return t[n][w];
    }
}
int main()
{
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
    memset(t, -1, sizeof(t));
    cout << knapsack(wt, val, w, wt.size());
    return 0;
}