#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int key)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int findEleInSortedArr(vector<int> &arr, int key)
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
            int res1 = binarySearch(arr, 0, mid - 1, key);
            int res2 = binarySearch(arr, mid, n, key);
            int res = max(res1, res2);
            return res;
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