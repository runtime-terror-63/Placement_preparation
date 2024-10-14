#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
  if (n <= 1)
    return 1;
  if (dp[n] != -1)
    return dp[n];
  int last = solve(n - 1, dp);
  int s_last = solve(n - 2, dp);
  return dp[n] = last + s_last;
}
int main()
{
  int n = 4;
  vector<int> dp(n + 1, -1);
  cout << solve(n, dp);
}