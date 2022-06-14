#include<bits/stdc++.h>
using namespace std;

void swap(int,int); //Function prototype

//Call by reference using pointers
void swapptr(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Call by reference using C++ reference variables
void swapref(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

//Return by reference
int & swapref1(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    return a;
}


int main(){
    int num1;
    int num2;
    cout<<"Enter first number"<<endl;
    cin>>num1;
    cout<<"Enter second number"<<endl;
    cin>>num2;
    cout<<"First number is "<<num1<<" and second number is "<<num2<<endl;
    //swapptr(&num1, &num2);  
    swapref(num1,num2);
    cout<<"First number is "<<num1<<" and second number is "<<num2<<endl;
    swapref1(num1,num2) = 800;
    cout<<"First number is "<<num1<<" and second number is "<<num2<<endl;
}

//This swap dosen't work
void swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}
