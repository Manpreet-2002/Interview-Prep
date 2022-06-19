#include <bits/stdc++.h>
using namespace std;

void f(int i, vector<int> &ans, vector<int> arr, int k)
{
    int n = arr.size();
    if (i >= n)
    {
        int count = 0;
        for (int j : ans)
        {
            count = count + j;
        }
        if (count == k)
        {
            for (int j : ans)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        return;
    }
    ans.push_back(arr.at(i));
    f(i + 1, ans, arr, k);
    ans.erase(std::remove(ans.begin(), ans.end(), arr.at(i)), ans.end());
    f(i + 1, ans, arr, k);
}

int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    int k = 5;

    vector<int> ans;

    f(0, ans, arr, k);
    return 0;
}