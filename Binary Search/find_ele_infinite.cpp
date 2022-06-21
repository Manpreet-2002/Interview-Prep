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
int binaryInfiniteArr(vector<int> &arr, int key)
{
    int start = 0;
    int end = 1;
    while (key > arr[end])
    {
        start = end;
        end = end * 2;
    }
    int res = binarySearch(arr, start, end, key);
    return res;
}