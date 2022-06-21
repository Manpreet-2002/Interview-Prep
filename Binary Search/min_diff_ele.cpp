#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int> &arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return key;
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
    if (abs(arr[start] - key) > abs(arr[end] - key))
    {
        return arr[end];
    }
    else
    {
        return arr[start];
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(15);
    cout << minDiff(arr, 14);
}