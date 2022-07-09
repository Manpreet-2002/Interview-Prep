#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    }
    else if (wt[n - 1] > w)
    {
        return knapsack(wt, val, w, n - 1);
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
    cout << knapsack(wt, val, w, wt.size());
    return 0;
}