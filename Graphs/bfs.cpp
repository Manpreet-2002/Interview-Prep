#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> graph[N];
int vis[N];
int level[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int child : graph[curr])
        {
            if (vis[child])
                continue;
            q.push(child);
            vis[child] = 1;
            level[child] = level[curr] + 1;
        }
    }
}
// Time complexity is O(V+2E) or O(V+E)
// If weights of all edges are same, then BFS gives the shorest distance between two points
int main()
{
    int v;
    cin >> v;
    for (int i = 0; i < v - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    return 0;
}