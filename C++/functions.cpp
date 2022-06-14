#include<bits/stdc++.h>
using namespace std; 

inline int prod(int a,int b){
    return a*b;
}

int product(int a,int b){
    static int c = 0; //This executes only once
    c++;
    return a*(b+c);
}
//lol
int main(){
    int a,b;
    cin>>a>>b;
    cout<<prod(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    cout<<product(a,b)<<endl;
    return 0;
}