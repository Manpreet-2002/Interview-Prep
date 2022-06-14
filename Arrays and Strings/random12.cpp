#include<vector>
#include<unordered_map>
#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(t == ""){return "";}
        
        unordered_map<char,int> countT;
        unordered_map<char,int> window;
        
        for(int i=0;i<t.length();i++){
            countT[t.at(i)]++;
        }
        int have = 0;
        int need = countT.size();
        int start = 0;
        int end = 0;
        int res[2];
        res[0] = -1;
        res[1] = -1;
        int reslen = INT_MAX;
        string ans;
        
        for(end=0;end<s.length();end++){
            char c = s.at(end);
            window[c]++;
            if(countT.find(c) != countT.end() && window[c] == countT[c]){
                have++;
            }
            
            while(have == need){
                //update the result
                if(end-start+1 < reslen){
                    res[0] = start;
                    res[1] = end;
                    reslen = end-start+1;
                }
                //pop the leftmost element of the window
                window[s.at(start)]--;
                if(countT.find(s.at(start)) != countT.end() && window[s.at(start)] < countT[s.at(start)]){
                    have--;
                }
                start++;
            }
        }
        if(reslen != INT_MAX){
            for(int i=res[0];i<=res[1];i++){
                ans.push_back(s.at(i));
            }
            return ans;
        }
        return "";
    }
};