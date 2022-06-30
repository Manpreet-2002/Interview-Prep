#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<int> freqSort(vector<int> &arr)
{
    vector<int> ans;
    unordered_map<int, int> freq;
    priority_queue<pi> maxh;
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
        maxh.push(make_pair(i->second, i->first));
    }
    while (maxh.size())
    {
        int freq_count = maxh.top().first;
        while (freq_count)
        {
            ans.push_back(maxh.top().second);
            freq_count--;
        }
        maxh.pop();
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
    vector<int> ans = freqSort(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}