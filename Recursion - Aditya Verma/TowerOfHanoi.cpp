#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d, int h, int n, long long &count)
{
    if (n == 1)
    {
        count++;
        return;
    }
    solve(s, h, d, n - 1, count);
    count++;
    solve(h, d, s, n - 1, count);
    return;
}
int main()
{
    long long count = 0;
    solve(1, 2, 3, 2, count);
    cout << count;
}