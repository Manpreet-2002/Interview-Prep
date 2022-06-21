#include <bits/stdc++.h>
using namespace std;

int floorOfEle(vector<int> &arr, int key)
{
    int start = 0;
    int end = arr.size() - 1;
    int res = 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            return arr[mid];
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            res = arr[mid];
            start = mid + 1;
        }
    }
    return res;
}
int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    cout << floorOfEle(arr, 15);
}