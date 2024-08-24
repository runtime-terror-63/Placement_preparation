#include <bits/stdc++.h>
using namespace std;

// Tc - O(n)
// Sc - O(1)
int maximum_Consecutive_ones(vector<int> arr, int n)
{
  int cnt = 0, maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 1)
      cnt++;
    if (maxi < cnt)
      maxi = cnt;
    if (arr[i] == 0)
      cnt = 0;
  }
  return maxi;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << maximum_Consecutive_ones(arr, n);
}