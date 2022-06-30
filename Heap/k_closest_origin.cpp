#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<pair<int, int>> kClosestOrigin(vector<pair<int, int>> &arr, int k)
{
    priority_queue<pair<float, pi>> maxh;
    vector<pair<int, int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i].first;
        int y = arr[i].second;
        float square = x * x + y * y;
        float distance = sqrt(square);
        maxh.push(make_pair(distance, arr[i]));
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    while (maxh.size() != 0)
    {
        ans.push_back(maxh.top().second);
        maxh.pop();
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> arr;
    arr.push_back({1, 3});
    arr.push_back({-2, 2});
    arr.push_back({5, 8});
    arr.push_back({0, 1});
    vector<pair<int, int>> ans = kClosestOrigin(arr, 2);
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}