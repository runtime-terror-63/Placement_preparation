#include <bits/stdc++.h>
using namespace std;
/*
memorization solution
tc: O(N)
sc: O(n) + O(n)
    stack + array
    space
*/
int solve(int arr[], int n, vector<int> dp)
{
  if (n == 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  int jump2 = INT_MAX;
  int jump1 = solve(arr, n - 1, dp) + abs(arr[n] - arr[n - 1]);
  if (n > 1)
    jump2 = solve(arr, n - 2, dp) + abs(arr[n] - arr[n - 2]);
  return min(jump1, jump2);
}

int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> dp(n, -1);
  // cout << solve(arr, n - 1, dp);

  /*tabulation solution
  tc: O(N)
  sc: O(N)
  */
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    int jump2 = INT_MAX;
    int jump1 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
    if (i > 1)
      jump2 = dp[i - 2] + abs(arr[i] - arr[i - 2]);

    dp[i] = min(jump1, jump2);
  }

  // cout << dp[n - 1];

  /*tabulation solution OPTIMIZED
  tc: O(N)
  sc: O(1)
  */
  int prev = 0;
  int prev2 = 0;
  for (int i = 1; i < n; i++)
  {
    int jump1 = prev + abs(arr[i] - arr[i - 1]);
    int jump2 = INT_MAX;
    if (i > 1)
      jump2 = prev2 + abs(arr[i] - arr[i - 2]);

    int curri = min(jump1, jump2);
    prev2 = prev;
    prev = curri;
  }

  cout << prev << endl;
}