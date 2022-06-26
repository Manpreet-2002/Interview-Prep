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
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (s.top() > arr[i])
        {
            ans.push_back(s.top());
        }
        else if (s.top() <= arr[i])
        {
            while (!s.empty())
            {
                if (s.top() <= arr[i])
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
    for (int i = 0; i < ans.size(); i++)
    {
        int index_of_ngl;
        if (ans[i] == -1)
        {
            index_of_ngl = -1;
        }
        else
        {
            vector<int>::iterator itr = find(arr.begin(), arr.end(), ans[i]);
            index_of_ngl = distance(arr.begin(), itr);
        }
        ans[i] = i - index_of_ngl;
        cout << ans[i] << " ";
    }
    return 0;
}