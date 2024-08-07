#include <bits/stdc++.h>
using namespace std;

bool func(int ind, int sum, vector<int> &ds, vector<vector<int>> &ans, int k, vector<int> &arr, int n)
{
  if (ind == n)
  {
    if (sum == k)
    {
      for (auto it : ds)
        cout << it << " ";
      cout << endl;
      return true;
    }
    else
      return false;
  }
  ds.push_back(arr[ind]);
  if (func(ind + 1, sum + arr[ind], ds, ans, k, arr, n) == true)
    return true;
  ds.pop_back();
  // not pick
  if (func(ind + 1, sum, ds, ans, k, arr, n) == true)
    return true;
  return false;
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

  vector<vector<int>> ans;
  vector<int> ds;
  func(0, 0, ds, ans, k, arr, n);
  /*
    for (const auto &subset : ans)
    {
      for (const auto &num : subset)
      {
        cout << num << " ";
      }
      cout << endl;
    } */

  return 0;
}
