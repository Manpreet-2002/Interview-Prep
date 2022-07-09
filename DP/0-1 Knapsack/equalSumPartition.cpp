#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> arr, long int sum)
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
bool equalSumPartition(vector<int> &arr)
{
    long int sum;
    bool ans = false;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    else if (sum % 2 == 0)
    {
        ans = subsetSum(arr, sum / 2);
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(11);
    arr.push_back(5);
    if (equalSumPartition(arr))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}