#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
const int INF = 1e9 + 10;
vector<int> graph[N];
int vis[8][8];
int level[8][8];

pair<int, int> getCoord(string s)
{
    int x = s[0] - 'a';
    int y = s[1] - '1';
    return {x, y};
}

vector<pair<int, int>> movements = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

bool isValid(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int bfs(string source, string destination)
{
    pair<int, int> s = getCoord(source);
    pair<int, int> d = getCoord(destination);
    int s_x = s.first;
    int s_y = s.second;
    int d_x = d.first;
    int d_y = d.second;
    queue<pair<int, int>> q;
    q.push(s);
    vis[s_x][s_y] = 1;
    level[s_x][s_y] = 0;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        for (pair<int, int> movement : movements)
        {
            int x = movement.first + curr.first;
            int y = movement.second + curr.second;
            if (!isValid(x, y))
                continue;
            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            q.push({x, y});
            level[x][y] = level[curr.first][curr.second] + 1;
        }
        if (level[d_x][d_y] != INF)
        {
            break;
        }
    }
    return level[d_x][d_y];
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }
    return 0;
}