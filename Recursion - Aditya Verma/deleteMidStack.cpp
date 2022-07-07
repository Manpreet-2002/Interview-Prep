#include <bits/stdc++.h>
using namespace std;

stack<int> support;
void deleteMidEven(stack<int> &s)
{
    if (s.size() == support.size())
    {
        support.pop();
        while (support.size())
        {
            s.push(support.top());
            support.pop();
        }
        return;
    }
    int temp = s.top();
    s.pop();
    support.push(temp);
    deleteMidEven(s);
    return;
}
void deleteMidOdd(stack<int> &s)
{
    if (s.size() == support.size() + 1)
    {
        s.pop();
        while (support.size())
        {
            s.push(support.top());
            support.pop();
        }
        return;
    }
    int temp = s.top();
    s.pop();
    support.push(temp);
    deleteMidOdd(s);
    return;
}
void deleteMid(stack<int> &s)
{
    if (s.size() % 2 == 0)
    {
        deleteMidEven(s);
    }
    else
    {
        deleteMidOdd(s);
    }
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
    deleteMid(s);
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}