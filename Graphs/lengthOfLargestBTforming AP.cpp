#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
int par[N];

void dfs1(int vertex, int parent = -1)
{
    for (int child : graph[vertex])
    {
        if (child == parent)
        {
            continue;
        }
        par[child] = vertex;
        dfs1(child, vertex);
    }
}

int dfs(int vertex, int parent = -1)
{
    int maxNo = 0;
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        if (parent != -1)
        {
            if (vertex - child == parent - vertex)
            {
                maxNo = max(maxNo, 1 + dfs(child, vertex));
            }
            else
            {
                maxNo = max(maxNo, dfs(child, vertex));
            }
        }
        else
        {
            maxNo = max(maxNo, 1 + dfs(child, vertex));
        }
    }
    return (maxNo > 0) ? maxNo : 1;
}
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
    dfs1(6);
    int node;
    cin >> node;
    cout << dfs(node) << endl;
    cout << dfs(node, par[node]) << endl;
}