#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

bool vis[N];

void dfs(int vertex)
{
    // Take action on vertex after entering the vertex
    for (int child : graph[vertex])
    {
        // Take action on child node before entering the child node
        dfs(child);
        // Take action on child node after exiting the child node
    }
    // Take action on vertex before exiting the vertex
}
// Time complexity is O(V+2E) or O(V+E)
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
}