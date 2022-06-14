#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    int j=1;
    int next;
    int prev;
    int ans=0;

    while(j<n-1){
        next = max(arr[j],arr[j+1]);
        prev = max(arr[j],arr[j-1]);

        if(next==arr[j] && prev==arr[j]){
            ans+=1;
        }
        j++;
    }
    if(arr[0]>arr[1]){
        ans+=1;
    }
    if(arr[n-1]>arr[n-2]){
        ans+=1;
    }
    cout<<ans<<endl;
}