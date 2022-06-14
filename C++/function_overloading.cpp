#include<bits/stdc++.h>
using namespace std;

int sum(int a, int b){
    cout<<"Using only 2 arguments "<<endl;
    return a+b;
}

int sum(int a, int b, int c){
    cout<<"Using only 3 arguments "<<endl;
    return a+b+c;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<endl;
    cout<<"Sum of "<<a<<" and "<<b<<" is "<<sum(a,b)<<endl;
    cout<<"Sum of "<<a<<" and "<<b<<" and "<<c<<" is "<<sum(a,b,c)<<endl;
}