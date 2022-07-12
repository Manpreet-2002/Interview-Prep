#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

bool vis[N];

bool dfs(int vertex, int parent)
{
    bool isLoop = false;
    vis[vertex] = true;
    for (int child : graph[vertex])
    {
        if (vis[child] == true and child == parent)
            continue;
        if (vis[child] == true)
            return true;
        isLoop = isLoop || dfs(child, vertex);
    }
    return isLoop;
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
    bool isLoop;
    for (int i = 1; i <= v; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            isLoop = true;
            break;
        }
    }
    cout << isLoop << endl;
    return 0;
}