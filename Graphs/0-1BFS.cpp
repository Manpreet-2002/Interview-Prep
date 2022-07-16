#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int INF = 1e9 + 10;
vector<pair<int, int>> graph[N];
vector<int> level(N, INF);

/**No need of visited array in this question ->
 * Each node can be processed atmost twice
 * For eg ->
 *      1
 *     /\
 *    2  3
 *   /\ /\
 *  4  5  6
 * Here 5 can be processed twice - once going from 2 and one from 3.
 * If each edge has weight of either 0 or 1 then these 2 can give different ans.
 * If we would have used visited array -> that means each node can be processed only once
 * Deque is used in 0-1 BFS
 * **/

int n, m;
int bfs(int source)
{
    deque<int> q;
    q.push_front(source);
    level[source] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop_front();
        cout << curr << " ";
        for (pair<int, int> child : graph[curr])
        {
            int node = child.first;
            int wt = child.second;
            if (level[curr] + wt < level[node])
            {
                level[node] = level[curr] + wt;
                if (wt == 1)
                {
                    q.push_back(node);
                }
                else
                {
                    q.push_back(node);
                }
            }
        }
    }
    return (level[n] == INF) ? -1 : level[n];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        if (v1 == v2)
            continue;
        graph[v1].push_back({v2, 0});
        graph[v2].push_back({v1, 1});
    }
    return 0;
}