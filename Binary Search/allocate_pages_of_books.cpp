#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &arr, int n, int k, int mid)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            student++;
            sum = arr[i];
        }
        if (student > k)
        {
            return false;
        }
    }
    return true;
}

int allocatePagesOfBooks(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n < k)
    {
        return -1;
    }
    int maxNo = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxNo = max(maxNo, arr[i]);
        sum += arr[i];
    }
    int start = maxNo;
    int end = sum;
    int res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, k, mid) == true)
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}