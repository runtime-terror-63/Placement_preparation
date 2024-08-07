#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> ds, int arr[], int n)
{
  if (n == ind)
  {

    for (auto it : ds)
      cout << it << " ";
    if (ds.size() == 0)
      cout << "[]" << endl;
    cout << endl;
    return;
  }
  ds.push_back(arr[ind]);
  solve(ind + 1, ds, arr, n);
  ds.pop_back();
  solve(ind + 1, ds, arr, n);
}
int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> ds;
  solve(0, ds, arr, n);
}