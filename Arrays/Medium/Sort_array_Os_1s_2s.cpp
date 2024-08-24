#include <bits/stdc++.h>
using namespace std;

void sort_array(vector<int> arr, int n)
{
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] == 0)
      cnt0++;
  for (int i = 0; i < n; i++)
    if (arr[i] == 1)
      cnt1++;
  for (int i = 0; i < n; i++)
    if (arr[i] == 2)
      cnt2++;

  for (int i = 0; i < cnt0; i++)
    arr[i] = 0;
  for (int i = cnt0; i < cnt0 + cnt1; i++)
    arr[i] = 1;
  for (int i = cnt0 + cnt1; i < n; i++)
    arr[i] = 2;

  for (int i = 0; i < n; i++)
    cout << arr[i];
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort_array(arr, n);
}