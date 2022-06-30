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
int sumOfNumbers(vector<int> &arr, int k1, int k2)
{
    auto k1_itr = find(arr.begin(), arr.end(), k_smallest(arr, k1));
    int k1_index = distance(k1_itr, arr.begin());
    auto k2_itr = find(arr.begin(), arr.end(), k_smallest(arr, k2));
    int k2_index = distance(k2_itr, arr.begin());
    int sum = 0;
    for (int i = k1_index; i <= k2_index; i++)
    {
        sum += arr[i];
    }
    return sum;
}