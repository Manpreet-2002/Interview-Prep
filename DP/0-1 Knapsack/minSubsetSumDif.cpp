#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int subsetSum(vector<int> arr, int sum)
{
    bool t[arr.size() + 1][sum + 1];
    for (int i = 0; i < arr.size() + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }
    for (int i = 1; i < arr.size() + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    int mn = INT_MAX;
    vector<int> v;
    for (int i = 0; i < (sum + 1) / 2; i++)
    {
        if (t[arr.size()][i] == true)
        {
            v.push_back(i);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, sum - 2 * v[i]);
    }
    return mn;
}
int minSubsetSymDif(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return subsetSum(arr, sum);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    cout << minSubsetSymDif(arr);
    return 0;
}