#include <bits/stdc++.h>
using namespace std;

// TC - O(N3)
// SC - O(1)
int count_subarray_sum(vector<int> arr, int n, int target)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k <= j; k++)
      {
        sum += arr[k];
      }
      if (sum == target)
        cnt++;
    }
  }
  return cnt;
}

// TC - O(N2)
// SC - O(1)
int countsubarray_sum(vector<int> arr, int n, int target)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {

      sum += arr[j];
      if (sum == target)
        cnt++;
    }
  }
  return cnt;
}

int countSubarraySum(vector<int> arr, int n, int k)
{
  unordered_map<int, int> mpp;
  mpp[0] = 1;
  int preSum = 0, cnt = 0;
  for (int i = 0; i < n; i++)
  {
    preSum += arr[i];
    int remove = preSum - k;
    cnt += mpp[remove];
    mpp[preSum] += 1;
  }

  return cnt;
}

int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << countSubarraySum(arr, n, target);
}