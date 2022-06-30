#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<int> kFrequent(vector<int> &arr, int k)
{
    vector<int> ans;
    unordered_map<int, int> freq;
    priority_queue<pi, vector<pi>, greater<pi>> minh;
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
        minh.push(make_pair(i->second, i->first));
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    while (minh.size())
    {
        ans.push_back(minh.top().second);
        minh.pop();
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(2);
    vector<int> ans = kFrequent(arr, 2);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}