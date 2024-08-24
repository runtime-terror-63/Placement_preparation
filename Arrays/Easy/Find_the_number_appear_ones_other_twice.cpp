#include <bits/stdc++.h>
using namespace std;

// Bruteforce solution
//Tc - O(2n)
//Sc - O(n)
int number_appear_ones(vector<int> arr, int n)
{
  int curr = 0;
  for (int i = 0; i < n; i++)
  {
    curr = arr[i];
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[j] == curr)
        cnt++;
    }

    if (cnt == 1)
      return curr;
  }
  return -1;
}

// Hasing
//  Tc - O(n) +  O(n) + O(n)
//  Sc - O(n)
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
// TC - O(nlogM) + O((n/2)+1)
// Sc - O((n/2)+1)
int num_ones_apear(vector<int> arr, int n)
{
  map<int, int> mpp;
  int maxi = 0;
  for (auto it : arr) //  O(nlogM)
    mpp[it]++;
  for (auto it : mpp) // O((n/2)+1)
  {
    if (it.second == 1)
      maxi = it.first;
  }
  return maxi;
}

// Xor Operation
// Tc - O(n)
// Sc - O(1)
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
  cout << number_appear_ones(arr, n);
}
