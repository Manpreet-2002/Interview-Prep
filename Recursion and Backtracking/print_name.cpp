#include<bits/stdc++.h>
using namespace std;

void f(int count){
    if(count == 0){
        return;
    }
    cout<<"Manpreet"<<endl;
    count--;
    f(count);
}
int main(){
    int n;
    cin>>n;
    f(n);
    return 0;
}