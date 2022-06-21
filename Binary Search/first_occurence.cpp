#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int res = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == key)
        {
            res = mid;
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
    return res;
}

// Time complexity is O(log n) [log base 2]