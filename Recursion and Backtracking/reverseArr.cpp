#include<bits/stdc++.h>
using namespace std;

void f(vector<int>& vect, int l){
    int r = vect.size()-1-l;
    if(l>=r){
        return;
    }
    swap(vect.at(l),vect.at(r));
    f(vect,l+1);
}
int main(){
    vector<int> vect{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    f(vect,0);
    for(auto num : vect){
        cout<<num<<" ";
    }
}