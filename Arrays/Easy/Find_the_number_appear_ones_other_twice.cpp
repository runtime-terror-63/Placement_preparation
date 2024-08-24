#include <bits/stdc++.h>
using namespace std;

// Tc - O(n) +  O(n) + O(n)
// Sc - O(n)
int num_appear_ones(vector<int> arr, int n)
{
  int maxi = *max_element(arr.begin(), arr.end());
  vector<int> ans;
  vector<int> hash(maxi + 1, 0);
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }

  for (int i = 0; i < n; i++)
  {
    if (hash[arr[i]] == 1)
      return arr[i];
  }
  return -1;
}

// mapping
// TC - O(nlogn) + O(n)
// Sc - O(m)
int num_ones_apear(vector<int> arr, int n)
{
  map<int, int> mpp;
  int maxi = 0;
  for (auto it : arr)
    mpp[it]++;
  for (auto it : mpp)
  {
    if (it.second == 1)
      maxi = it.first;
  }
  return maxi;
}

// Xor Operation
int num_ones(vector<int> arr, int n)
{
  int xorr = 0;
  for (int i = 0; i < n; i++)
    xorr ^= arr[i];
  return xorr;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << num_ones(arr, n);
}