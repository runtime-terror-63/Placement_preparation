#include <bits/stdc++.h>
using namespace std;

void move_zero_end(vector<int> arr, int n)
{
  vector<int> temp;
  for (int i = 0; i < n; i++)
    if (arr[i] != 0)
      temp.push_back(arr[i]);

  for (int i = 0; i < temp.size(); i++)
    arr[i] = temp[i];
  for (int i = temp.size(); i < n; i++)
    arr[i] = 0;

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  move_zero_end(arr, n);
}