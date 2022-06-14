#include<bits/stdc++.h>
using namespace std;

void f(int count, int &n){
    if(count>n){
        return;
    }
    f(count+1,n);
    cout<<count<<" ";
}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    int count = 1;
    f(count,n);
}