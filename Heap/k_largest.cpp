#include <bits/stdc++.h>
using namespace std;

vector<int> k_largest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    while (minh.size())
    {
        ans.push_back(minh.top());
        minh.pop();
    }
    return ans;
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
    vector<int> ans = k_largest(arr, 3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}