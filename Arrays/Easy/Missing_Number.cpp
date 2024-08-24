#include <bits/stdc++.h>
using namespace std;

// TC - O(2n)
// Sc - O(1)
int missingNumber(vector<int> &nums)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    bool flag = 0;
    for (int j = 0; j < n; j++)
    {
      if (nums[j] == i)
      {
        flag = 1;
        break;
      }
    }

    if (flag == 0)
      return i;
  }
  return n;
}

// hash size array
//TC - O(n) + O(n) = O(2n)
//Sc - O(n)
int miss_Num(vector<int> arr, int n)
{
  int hash[n + 1] = {0};
  for (int i = 0; i < n; i++)
    hash[arr[i]] = 1;

  for (int i = 0; i < n; i++)
    if (hash[i] == 0)
      return i;

  return -1;
}

//summation approch
//TC - O(n)
//Sc - O(1)
int miss_Num(vector<int> arr, int n)
{
  int ans =( n*(n+1))/2;
  int sum = 0;
  for(int i = 0; i<n; i++) sum += arr[i];

  return ans - sum;
}


int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << miss_Num(arr, n);
}
