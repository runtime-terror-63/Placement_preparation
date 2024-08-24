#include <bits/stdc++.h>
using namespace std;

// TC - O(n3)
// Sc - O(1)
void longestSubarray(vector<int> arr, int n, int k)
{
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k <= j; k++)
        sum += arr[k];
      if (sum == k)
        len = max(len, j - i + 1);
    }
  }
  cout << len << endl;
}

// TC - O(n2)
// Sc - O(1)
void longest_Subarray(vector<int> arr, int n, int k)
{
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[k];
      if (sum == k)
        len = max(len, j - i + 1);
    }
  }
  cout << len << endl;
}

// prefix sum
// TC - O(n*log n)
// Sc - O(n)
int longest_subArray(vector<int> arr, int n, long long k)
{
  map<long long, int> prefSum;
  int maxLen = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (sum == k)
      maxLen = max(maxLen, i + 1);

    long long rem = sum - k;
    if (prefSum.find(rem) != prefSum.end())
    {
      int len = i - prefSum[rem];
      maxLen = max(maxLen, len);
    }
    if (prefSum.find(sum) == prefSum.end())
      prefSum[sum] = i;
  }
  return maxLen;
}

// TWO POINTER
// TC - O(2n)
// Sc - O(1)
int long_subarray(vector<int> arr, int n, int k)
{
  int left = 0, right = 0;
  int sum = arr[0];
  int maxLen = 0;
  while (right < n)
  {
    while (left <= right && sum > k)
    {
      sum -= arr[left];
      left++;
    }
    if (sum == k)
      maxLen = max(maxLen, right - left + 1);
    right++;
    if (right < n)
      sum += arr[right];
  }
  return maxLen;
}

int main()
{
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << long_subarray(arr, n, k);
}