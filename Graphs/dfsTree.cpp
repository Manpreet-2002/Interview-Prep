#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
int depth[N];
int height[N];
/*
<-----------NORMAL DFS ON TREES----------->
void dfs(int vertex, int parent = 0)
{
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}
*/
void dfs(int vertex, int parent = 0)
{
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    for (int i = 1; i <= e; i++)
    {
        cout << depth[i] << " " << height[i] << endl;
    }
    return 0;
}