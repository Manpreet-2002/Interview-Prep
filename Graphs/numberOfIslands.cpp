#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> graph[N];

bool vis[N][N];

void dfs(int i, int j, vector<vector<char>> &grid)
{
    if (j < 0 || i < 0)
    {
        return;
    }
    if (j >= grid[0].size() || i >= grid.size())
    {
        return;
    }

    if (grid[i][j] != '1')
    {
        return;
    }
    if (vis[i][j])
    {
        return;
    }
    vis[i][j] = true;

    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}

int numIslands(vector<vector<char>> &grid)
{
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (vis[i][j] != true && grid[i][j] == '1')
            {
                ans++;
                dfs(i, j, grid);
            }
        }
    }
    return ans;
}

int main()
{
}