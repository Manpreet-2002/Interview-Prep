#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

/**NOOB SOLUTION
 * Theorem -> With any node as root, find max depth node
 * Theorem says that this max depth node will always be one end of the diameter
 * With this max depth node, find its height. This height will give the diameter of the tree.
vector<int> height(N, 0);

void dfs(int vertex, int parent = 0)
{
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        height[vertex] = max(1 + height[child], height[vertex]);
    }
}
*/

int depth[N];
int height[N];

void dfs(int vertex, int parent = 0)
{
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[child] + 1, height[vertex]);
    }
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
    int maxIndex = 0;
    int maxNo = 0;
    dfs(1);
    for (int i = 1; i <= v; i++)
    {
        if (depth[i] > maxNo)
        {
            maxIndex = i;
            maxNo = depth[i];
        }
    }
    dfs(maxIndex);
    cout << height[maxIndex] << endl;
    return 0;
}