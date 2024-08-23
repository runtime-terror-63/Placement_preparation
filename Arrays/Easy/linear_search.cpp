#include<bits/stdc++.h>
using namespace std;

//TC - O(n)
//SC - O(1)
bool linear_search(vector<int>arr, int n, int target){
  for(int i = 0; i<n; i++) if(arr[i]==target)  return true;

  return false;
}
int main(){
  int n;
  cin>>n;
  vector<int>arr;
  int target;
  cin>>target;
  for(int i=0; i<n; i++) cin>>arr[i];
  if(linear_search(arr, n, target)) cout<<"found the target";
  else cout<<"Not found the target";
}
