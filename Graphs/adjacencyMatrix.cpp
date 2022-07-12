#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int graph1[N][N];

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;
    }
    // O(N^2) -> space complexity
    // N can be max 1e3 or 1e4

    // Advantage is it can tell if 2 vertices are connected or not in O(1)
}