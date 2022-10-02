#include <bits/stdc++.h>
using namespace std;
constexpr static int N = 1e5;
void dfs(map<string, set<string>> &mp, string key, vector<string> &ans)
{
    ans.push_back(key);
    if (mp[key].size() == 0)
    {
        return;
    }
    auto it = mp[key].begin();
    string node = *it;
    mp[key].erase(it);
    dfs(mp, node, ans);
}
vector<string> findItinerary(vector<vector<string>> &tickets)
{
    map<string, set<string>> mp;
    for (auto ticket : tickets)
    {
        mp[ticket[0]].insert(ticket[1]);
    }
    vector<string> ans;
    string toSearch = "JFK";
    dfs(mp, toSearch, ans);
    return ans;
}
int main()
{
    vector<vector<string>> tickets =
        {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> ans = findItinerary(tickets);
    for (auto s : ans)
    {
        cout << s << " ";
    }
    return 0;
}