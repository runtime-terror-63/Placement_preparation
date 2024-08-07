#include <bits/stdc++.h>
using namespace std;
/*
void solve(int l, int r, int arr[])
{
  if (l >= r)
    return;
  swap(arr[l], arr[r]);
  solve(l + 1, r - 1, arr);
}
*/

void solve(int i, int n, int arr[])
{
  if (i >= n / 2)
    return;
  swap(arr[i], arr[n - i - 1]);
  solve(i + 1, n, arr);
}
int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  // solve(0, n - 1, arr);
  solve(0, n, arr);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}