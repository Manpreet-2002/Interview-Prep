#include <bits/stdc++.h>
using namespace std;

int k_smallest(vector<int> &arr, int k)
{
    priority_queue<int> maxh;
    for (int i = 0; i < arr.size(); i++)
    {
        maxh.push(arr[i]);
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    return maxh.top();
}
int main()
{
    vector<int> arr;
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(20);
    arr.push_back(15);
    cout << k_smallest(arr, 3);
    return 0;
}