#include <bits/stdc++.h>
using namespace std;

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
      cout << "curr-> " << curr << endl;
      curr += 1;
      cnt += 1;
    }
    maxi = max(maxi, cnt);
  }
  return maxi;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << longest_consequtive_subsequence(arr, n);
}