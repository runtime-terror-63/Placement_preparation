#include <bits/stdc++.h>
using namespace std;
// memorization
// tc- O(n)
// sc - O(n) + O(n)
int fn(int n, vector<int> &dp)
{
  if (n <= 1)
    return n;
  if (dp[n] != -1)
    return dp[n];                               // one step
  return dp[n] = fn(n - 1, dp) + fn(n - 2, dp); // two step
}

int main()
{
  int n;
  cin >> n;
  // vector<int> dp(n + 1, -1);   //declarations
  // cout << fn(n, dp);

  // tabulation
  // tc - O(n)
  // sc - O(1)
  int prev2 = 0;
  int prev1 = 1;
  for (int i = 2; i <= n; i++)
  {
    int curr = prev2 + prev1;
    prev2 = prev1;
    prev1 = curr;
  }

  // tabulation
  // tc - O(n)
  // sc - O(n)
  vector<int> dp(n + 1, -1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

  cout << dp[n];
}