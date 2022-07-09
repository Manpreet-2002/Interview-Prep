#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> arr, int sum)
{
    int t[arr.size() + 1][sum + 1];
    for (int i = 0; i < arr.size() + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }
    for (int i = 1; i < arr.size() + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[arr.size()][sum];
}
int countSubsetSumGivenDif(vector<int> &arr, int dif)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    int res = (sum + dif) / 2;
    return subsetSum(arr, res);
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
    int dif;
    cin >> dif;
    cout << countSubsetSumGivenDif(arr, dif);
    return 0;
}