#include<iostream>

using namespace std;

//Idea: if arr[i] > arr[i+1] swap them. To place the element in their respective position, we have to do the following operation N-1 times. 
//Time Complexity: O(N2)

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    int counter=1;

    while(counter<n){
        for(int i=0;i < n-counter; i++){
            if(arr[i+1]<arr[i]){
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
        counter++;
    }

    for(int m=0;m<n;m++){
        cout<<arr[m]<<" ";
    }

    return 0;
}