#include <bits/stdc++.h>
using namespace std;

// SUBSET SUM RECURSIVE SOLUTION STARTS HERE
bool subsetSumRecursive(vector<int> &arr, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n >= 0)
    {
        if (arr[n] > sum)
        {
            return subsetSumRecursive(arr, sum, n - 1);
        }
        else if (arr[n] <= sum)
        {
            return (subsetSumRecursive(arr, sum, n - 1) || subsetSumRecursive(arr, sum - arr[n], n - 1));
        }
    }
    else
    {
        return false;
    }
}
// SUBSET SUM RECURSIVE SOLUTION ENDS HERE

// SUBSET SUM MEMOIZE SOLUTION STARTS HERE
bool static t[6][15];
bool subsetSumMemoize(vector<int> &arr, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (t[n][sum])
    {
        return t[n][sum];
    }
    if (n >= 0)
    {
        if (arr[n] > sum)
        {
            t[n][sum] = subsetSumMemoize(arr, sum, n - 1);
        }
        else if (arr[n] <= sum)
        {
            t[n][sum] = (subsetSumMemoize(arr, sum, n - 1) || subsetSumMemoize(arr, sum - arr[n], n - 1));
        }
        return t[n][sum];
    }
    else
    {
        return false;
    }
}
// SUBSET SUM MEMOIZE SOLUTION ENDS HERE

// SUBSET SUM TOP DOWN APPROACH STARTS HERE
bool subsetSum(vector<int> arr, int sum)
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
    return t[arr.size()][sum];
}
// SUBSET SUM TOP DOWN APPROACH ENDS HERE

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(10);
    int sum = 11;
    cout << subsetSum(arr, sum);
    return 0;
}