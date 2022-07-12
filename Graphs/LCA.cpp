#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
int par[N];

/**Logic is that we write down the path from vertex to node1 and node2
 * Till where the 2 paths are common, they share the same ancestor
 * the last common ancestor we have to return
 * To make the path array, we use dfs to maintain parent array
 * We push back the vertex and all it's parents till we reach the root node
 * Time complexity -> O(N)
 */

void dfs(int vertex, int parent = 0)
{
    par[vertex] = parent;
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
    }
}

vector<int> path(int vertex)
{
    vector<int> ans;
    while (vertex != 0)
    {
        ans.push_back(vertex);
        vertex = par[vertex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int lca(vector<int> path1, vector<int> path2)
{
    int size1 = path1.size();
    int size2 = path2.size();
    int size = (size1 > size2) ? size2 : size1;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (path1[i] == path2[i])
        {
            ans = path1[i];
            continue;
        }
        else
        {
            return ans;
        }
    }
    return ans;
}

int main()
{
    int e;
    cin >> e;
    for (int i = 0; i < e - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    int x, y;
    cin >> x >> y;
    cout << lca(path(x), path(y)) << endl;
    return 0;
}