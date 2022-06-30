#include <bits/stdc++.h>
using namespace std;

int connectRopes(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        minh.push(arr[i]);
    }
    while (minh.size() != 1)
    {
        int a = minh.top();
        minh.pop();
        int b = minh.top();
        minh.pop();
        ans = ans + a + b;
        minh.push(a + b);
    }
    return ans;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    cout << connectRopes(arr) << endl;
    return 0;
}