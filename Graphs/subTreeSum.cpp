#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
/**Given Q queries, Q<=1e5
 * In each query given V,
 * Print subtree sum of V & Number of even numbers
 * in subtree of V
 **/

int sum[N];
int even[N];

void dfs(int vertex, int parent = 0)
{
    if (vertex % 2 == 0)
    {
        even[vertex]++;
    }
    sum[vertex] = vertex;
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        sum[vertex] = sum[vertex] + sum[child];
        even[vertex] = even[vertex] + even[child];
    }
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
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int v;
        cin >> v;
        cout << sum[v] << " " << even[v] << endl;
    }
    return 0;
}