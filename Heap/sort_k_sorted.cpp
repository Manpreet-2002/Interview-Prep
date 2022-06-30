#include <bits/stdc++.h>
using namespace std;

vector<int> kSorted(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> ans;
    for (int i = 0; i <= arr.size() - 1; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            ans.push_back(minh.top());
            minh.pop();
        }
    }
    while (minh.size() != 0)
    {
        ans.push_back(minh.top());
        minh.pop();
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(10);
    arr.push_back(9);
    vector<int> ans = kSorted(arr, 3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}