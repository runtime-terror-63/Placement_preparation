#include <bits/stdc++.h>
using namespace std;
/* recursion technique
int solve(vector<int> arr, int ind)
{
  if (ind == 0)
    return arr[ind];
  if (ind < 0)
    return 0;
  int pick = arr[ind] + solve(arr, ind - 2);
  int not_pick = 0 + solve(arr, ind - 1);

  return max(pick, not_pick);
} */

// memorization
/*
int solve(vector<int> arr, int ind)
{
  vector<int> dp(ind + 1, -1);
  if (ind == 0)
    return arr[ind];
  if (ind < 0)
    return 0;
  if (dp[ind] != -1)
    return dp[ind];
  int pick = arr[ind] + solve(arr, ind - 2);
  int notpick = solve(arr, ind - 1);

  dp[ind] = max(pick, notpick);
  return dp[ind];
}*/

int solve1(vector<int> arr, int ind)
{
  int prev = arr[0];
  int prev2 = 0;
  for (int i = 1; i < ind; i++)
  {
    int pick = arr[i];
    if (ind > 1)
      pick += prev2;
    int non_pick = prev;

    int curri = max(pick, non_pick);
    prev2 = prev;
    prev = curri;
  }
  return prev;
}

// tabulation
int tabulation(vector<int> &arr, int ind)
{
  vector<int> dp(ind, 0);
  dp[0] = arr[0];
  for (int i = 1; i < ind; i++)
  {
    int take = arr[i];
    if (i > 1)
      take += dp[i - 2];
    int not_take = dp[i - 1];

    dp[i] = max(take, not_take);
  }
  return dp[ind - 1];
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  // cout << solve(arr, n - 1);
  cout << tabulation(arr, n);
}