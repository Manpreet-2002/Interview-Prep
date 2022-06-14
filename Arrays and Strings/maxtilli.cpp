#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    int arr2[n];
    arr2[0] = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            arr2[i] = arr[i];
        }
        else{
            arr2[i] = arr2[i-1];
        }
    }

    for(int m=0;m<n;m++){
        cout<<arr2[m]<<" ";
    }
}