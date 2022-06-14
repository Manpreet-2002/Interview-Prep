#include<bits/stdc++.h>
using namespace std;

bool f(string &str, int l){
    int r = str.length()-1-l;
    if(l>=r){
        return true;
    }
    if(str.at(l) != str.at(r)){
        return false;
    } else{
        return f(str,l+1);
    }
}

int main(){
    string str = "11211";
    cout<<f(str,0)<<endl;
}