#include <bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &s, int k)
{
    if (s.size() == 0)
    {
        return;
    }
    if (k == 1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMid(s, k - 1);
    s.push(temp);
    return;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int k = s.size() / 2 + 1;
    deleteMid(s, k);
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}