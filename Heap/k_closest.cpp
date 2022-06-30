#include <bits/stdc++.h>
using namespace std;

vector<int> kClosest(vector<int> &arr, int k, int x)
{
    priority_queue<pair<int, int>> maxh;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        maxh.push(make_pair(abs(arr[i] - x), arr[i]));
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    while (maxh.size())
    {
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    vector<int> ans = kClosest(arr, 3, 7);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}