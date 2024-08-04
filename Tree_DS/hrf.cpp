#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[]){
    int x[10];
    for(int i=0;i<n; i++){
        if(arr[i] != 0) x = arr[i];
    } 
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int * arr = new int(n);
        for(int i=0; i<n; i++)cin>>arr[i];
        solve(n,arr);
    }
}