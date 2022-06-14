#include<bits/stdc++.h>
using namespace std;

int fibonacciNo(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 1;
    }
    return fibonacciNo(n-1)+fibonacciNo(n-2);
}

void fibonacciSeq(vector<int> &vect){
    static int count = 1;
    if(count > vect.size()){
        return;
    }
    vect.at(count-1) = fibonacciNo(count);
    count++;
    fibonacciSeq(vect);
}

int main(){
    int n;
    cin>>n;
    cout<<endl;
    vector<int> vect(n,0);
    fibonacciSeq(vect);
    for(auto num : vect){
        cout<<num<<" ";
    }
    return 0;
}