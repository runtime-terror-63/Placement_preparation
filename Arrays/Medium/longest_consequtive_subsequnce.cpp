#include <bits/stdc++.h>
using namespace std;

// TC - O(N2)
// SC - O(1)
bool linear_search(vector<int> &arr, int x, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == x)
      return true;
  }
  return false;
}
int longest_consequtive_subsequence(vector<int> &arr, int n)
{
  int maxi = 1;
  for (int i = 0; i < n; i++)
  {
    int curr = arr[i];
    int cnt = 1;
    while (linear_search(arr, curr + 1, n) == true)
    {
      curr += 1;
      cnt += 1;
    }
    maxi = max(maxi, cnt);
  }
  return maxi;
}

// TC - O(NlogN) + O(N)
// Sc - O(N)

int longest_consequtibe_subsec(vector<int> &arr, int n)
{
  if (n == 0)
    return arr.size();
  sort(arr.begin(), arr.end());
  int curr_cnt = 0, largest = 1, lastSmallest = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] - 1 == lastSmallest)
    {
      curr_cnt += 1;
      lastSmallest = arr[i];
    }
    else if (arr[i] != lastSmallest)
    {
      curr_cnt = 1;
      lastSmallest = arr[i];
    }
    largest = max(largest, curr_cnt);
  }
  return largest;
}

// MOST OPTIMAL  GOOGLE INTERVIEW
// TC - O(N) + O(2*N)
// SC - O(N)
int lon_consecutive_subsequence(vector<int> &arr, int n)
{
  unordered_set<int> st;
  int longest = 1;
  for (int i = 0; i < n; i++)
    st.insert(arr[i]);
  for (auto it : st)
  {
    if (st.find(it - 1) == st.end())
    {
      int cnt = 1;
      int x = it;
      while (st.find(x + 1) != st.end())
      {
        x += 1;
        cnt += 1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << lon_consecutive_subsequence(arr, n);
}
