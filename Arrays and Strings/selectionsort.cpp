#include<iostream>

using namespace std;

//Idea: The inner loop selects the minimum element in the unsorted array and places the elements in increasing order. 
//Time complexity: O(N2)

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                int temp=arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(int m=0;m<n;m++){
        cout<<arr[m]<<" ";
    }

    return 0;
}