#include <iostream>
#include <climits>

using namespace std;

int main(){
    int size_of_arr;
    cin>>size_of_arr;
    int arr[size_of_arr];

    for(int i=0;i<size_of_arr;i++){
        cin>>arr[i];
    }

    int maxNo, minNo;
    maxNo = INT_MIN;
    minNo = INT_MAX;

    for(int j=0;j<size_of_arr;j++){
        maxNo = max(maxNo, arr[j]);
        minNo = min(minNo,arr[j]);
    }

    cout<<"Max No is "<<maxNo<<endl;
    cout<<"Min No is "<<minNo<<endl;

    return 0;
}