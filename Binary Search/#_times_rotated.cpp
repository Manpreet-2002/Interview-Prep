#include <bits/stdc++.h>
using namespace std;

int noTimesRotated(vector<int> &arr)
{
    int start = 0;
    int n = arr.size();
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
        {
            return mid;
        }
        if (arr[mid] >= arr[start])
        {
            start = mid + 1;
        }
        else if (arr[mid] <= arr[mid])
        {
            end = mid - 1;
        }
    }
    return -1;
}

// Time complexity is O(log n) [log base 2]