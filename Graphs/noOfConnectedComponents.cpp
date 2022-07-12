#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

bool vis[N];

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex)
{
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for (int child : graph[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

int connectedComponents(int v)
{
    int ans = 0;
    for (int i = 1; i <= v; i++)
    {
        if (vis[i] == false)
        {
            ans++;
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
        }
    }
    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    cout << connectedComponents(v) << endl;
    for (auto c_cc : cc)
    {
        for (auto vertex : c_cc)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }
    return 0;
}