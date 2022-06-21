#include <bits/stdc++.h>
using namespace std;

int countOfElement(vector<int> &arr, int key)
{
    int firstOccur = firstOccurence(arr, key);
    int lastOccur = lastOccurence(arr, key);
    return lastOccur - firstOccur + 1;
}

int firstOccurence(vector<int> &arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int firstOccur = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
        {
            firstOccur = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
    }
    return firstOccur;
}
int lastOccurence(vector<int> &arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int lastOccur = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
        {
            lastOccur = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
    }
    return lastOccur;
}

// Time complexity is O(log n) [log base 2]