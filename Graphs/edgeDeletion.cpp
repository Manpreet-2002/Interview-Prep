#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
/**We precompute the sums of all subtrees and
 * try to find the max product of sum in 0(N) time by using a for loop
 **/

int sum[N];
int val[N];
const int M = 1e9 + 7;

void dfs(int vertex, int parent = 0)
{
    sum[vertex] += val[vertex];
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        sum[vertex] = sum[vertex] + sum[child];
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
    int w = sum[1] / 2;
    int minNo = INT_MAX;
    int minIndex = 0;
    long long ans;
    for (int i = 2; i <= e; i++)
    {
        int a1 = sum[1] - sum[i];
        int a2 = sum[i];
        ans = max(ans, a1 * 1LL * a2);
    }
    cout << ans % M;
    return 0;
}