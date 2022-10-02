#include <bits/stdc++.h>
using namespace std;

int func(string x)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < x.length(); i++)
    {
        mp[x[i]]++;
    }
    string y = "";
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (itr->second > 1)
        {
            y.push_back(itr->first);
        }
    }
    int n = x.length();
    int m = y.length();
}