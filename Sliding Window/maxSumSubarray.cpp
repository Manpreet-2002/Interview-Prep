#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k)
{
    int size = arr.size();
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MIN;
    while (j < size)
    {
        sum += arr[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans = max(sum, ans);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, 5, 1, 8, 9, 1};
    int k = 3;
    cout << solve(arr, k) << endl;
    return 0;
}
