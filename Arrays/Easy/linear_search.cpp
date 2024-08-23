#include<bits/stdc++.h>
using namespace std;

/*
Example 1:
Input: arr[]= 1 2 3 4 5, num = 3
Output: 2
Explanation: 3 is present in the 2nd index

Example 2:
Input: arr[]= 5 4 3 2 1, num = 5
Output: 0
Explanation: 5 is present in the 0th index
*/

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
