#include <bits/stdc++.h>
using namespace std;

char nextLetter(vector<char> &arr, char key)
{
    int start = 0;
    int end = arr.size() - 1;
    char res = '#';
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > key)
        {
            res = arr[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
}
int main()
{
    vector<char> arr;
    arr.push_back('a');
    arr.push_back('b');
    arr.push_back('f');
    arr.push_back('f');
    arr.push_back('g');
    arr.push_back('o');
    cout << nextLetter(arr, 'f');
}