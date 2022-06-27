#include <bits/stdc++.h>
using namespace std;

vector<int> ngl(vector<int> &arr)
{
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            ans.push_back(0);
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
                ans.push_back(0);
            }
            else
            {

                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return ans;
}

vector<int> ngr(vector<int> &arr)
{
    vector<int> ans;
    stack<int> s;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(0);
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
                ans.push_back(0);
            }
            else
            {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int rainwaterTrapping(vector<int> &arr)
{
    vector<int> ngl_arr = ngl(arr);
    vector<int> ngr_arr = ngr(arr);
    vector<int> min_arr;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (min(ngl_arr[i], ngr_arr[i]) >= arr[i])
        {
            ans = ans + min(ngl_arr[i], ngr_arr[i]) - arr[i];
        }
        else
        {
            continue;
        }
    }
    return ans;
}
int trap(vector<int> &height)
{
    int res = 0;
    int s = 0;
    int e = height.size() - 1;
    int leftMax = height.at(s);
    int rightMax = height.at(e);
    while (s < e)
    {
        if (leftMax < rightMax)
        {
            s++;
            leftMax = max(leftMax, height.at(s));
            res += leftMax - height.at(s);
        }
        else
        {
            e--;
            rightMax = max(rightMax, height.at(e));
            res += rightMax - height.at(e);
        }
    }
    return res;
}

int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(4);
    /*
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    */
    cout << trap(arr) << " ";
}
