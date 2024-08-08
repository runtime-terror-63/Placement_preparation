#include <bits/stdc++.h>
using namespace std;
int solve(int n, int arr[], int k)
{
  if (n == 0)
    return 0;
  int minStep = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if (n - i >= 0)
    {
      int jump = solve(n - i, arr, k) + abs(arr[n] - arr[n - i]);
      minStep = min(jump, minStep);
    }
  }
  return minStep;
}
int main()
{
  int n, k;
  cin >> n >> k;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << solve(n - 1, arr, k);
}