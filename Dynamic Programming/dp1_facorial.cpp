#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
// memorization
// tc- O(n)
// sc - O(n) + O(n)
=======
//memorization
//tc- O(n) 
//sc - O(n) + O(n)
>>>>>>> f2b27d5730bb35c740824cb8beb30a3730ebf2bb
int fn(int n, vector<int> &dp)
{
  if (n <= 1)
    return n;
  if (dp[n] != -1)
    return dp[n];                               // one step
  return dp[n] = fn(n - 1, dp) + fn(n - 2, dp); // two step
}

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

<<<<<<< HEAD
  // tabulation
  // tc - O(n)
  // sc - O(1)
=======
  //tabulation
  //tc - O(n)
  //sc - O(1)
>>>>>>> f2b27d5730bb35c740824cb8beb30a3730ebf2bb
  int prev2 = 0;
  int prev1 = 1;
  for (int i = 2; i <= n; i++)
  {
    int curr = prev2 + prev1;
    prev2 = prev1;
    prev1 = curr;
  }

<<<<<<< HEAD
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
=======
  cout << prev1 << endl;
}
>>>>>>> f2b27d5730bb35c740824cb8beb30a3730ebf2bb
