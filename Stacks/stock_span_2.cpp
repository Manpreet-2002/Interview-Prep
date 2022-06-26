#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(100);
    arr.push_back(80);
    arr.push_back(60);
    arr.push_back(70);
    arr.push_back(60);
    arr.push_back(75);
    arr.push_back(85);
    vector<int> ans;
    stack<pair<int, int>> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (s.top().first > arr[i])
        {
            ans.push_back(s.top().second);
        }
        else if (s.top().first <= arr[i])
        {
            while (!s.empty())
            {
                if (s.top().first <= arr[i])
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

                ans.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = i - ans[i];
        cout << ans[i] << " ";
    }
    return 0;
}