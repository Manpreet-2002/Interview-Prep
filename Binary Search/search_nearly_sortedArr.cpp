#include <bits/stdc++.h>
using namespace std;

int modifiedBinarySearch(vector<int> &arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (mid - 1 >= start && arr[mid - 1] == key)
        {
            return mid - 1;
        }
        if (mid + 1 <= end && arr[mid + 1] == key)
        {
            return mid + 1;
        }
        if (arr[mid] > key)
        {
            end = mid - 2;
        }
        else
        {
            start = mid + 2;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(30);
    arr.push_back(20);
    arr.push_back(40);
    cout << modifiedBinarySearch(arr, 30);
}