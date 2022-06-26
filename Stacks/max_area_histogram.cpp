#include <bits/stdc++.h>
using namespace std;

vector<int> nsl(vector<int> &arr)
{
    vector<int> ans;
    stack<pair<int, int>> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (s.top().first < arr[i])
        {
            ans.push_back(s.top().second);
        }
        else if (s.top().first >= arr[i])
        {
            while (!s.empty())
            {
                if (s.top().first >= arr[i])
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
    return ans;
}
vector<int> nsr(vector<int> &arr)
{
    vector<int> ans;
    stack<pair<int, int>> s;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (s.top().first < arr[i])
        {
            ans.push_back(s.top().second);
        }
        else if (s.top().first >= arr[i])
        {
            while (!s.empty())
            {
                if (s.top().first >= arr[i])
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
    reverse(ans.begin(), ans.end());
    return ans;
}
int maxAreaHistogram(vector<int> &arr)
{
    vector<int> nsl_array = nsl(arr);
    vector<int> nsr_array = nsr(arr);
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int nsl_index, nsr_index;
        if (nsl_array[i] == -1)
        {
            nsl_index = -1;
        }
        else
        {
            nsl_index = nsl_array[i];
        }
        if (nsr_array[i] == -1)
        {
            nsr_index = arr.size();
        }
        else
        {
            nsr_index = nsr_array[i];
        }
        ans = max(ans, arr[i] * (nsr_index - nsl_index - 1));
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(6);
    cout << maxAreaHistogram(arr) << " ";
}
