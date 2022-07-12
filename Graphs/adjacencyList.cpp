#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<pair<int, int>> graph2[N];

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph2[v1].push_back({v2, wt});
        graph2[v2].push_back({v1, wt});
    }
    // O(V*E) -> space complexity
    // V can be max 1e5
    // E can be max 1e7
}