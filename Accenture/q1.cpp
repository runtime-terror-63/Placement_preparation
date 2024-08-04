#include<bits/stdc++.h>
using namespace std;
int calculateTotal(int r, int unit, int n, int arr[]){
  int total = r*unit;
  int sum = 0, i=0;
  for(i=0; i<n; i++){
     sum += arr[i];
    if(sum >= total) break;
  }
  return i+1;
}
int main(){
  int r;
  cin>>r;
  int unit;
  cin>>unit;
  int n;
  cin>>n;
  int * arr = new int[n];
  for(int i=0; i<n; i++) cin>>arr[i];
  cout<<calculateTotal(r, unit, n, arr);

}