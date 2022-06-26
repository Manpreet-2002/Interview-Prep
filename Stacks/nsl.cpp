#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(10);
    arr.push_back(8);
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (s.top() < arr[i])
        {
            ans.push_back(s.top());
        }
        else if (s.top() >= arr[i])
        {
            while (!s.empty())
            {
                if (s.top() >= arr[i])
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}