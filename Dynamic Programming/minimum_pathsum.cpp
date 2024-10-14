#include <bits/stdc++.h>
using namespace std;

int minimum_path(int i, int j, vector<vector<int>> &arr)
{
  if (i == 0 && j == 0)
    return arr[i][j];
  if (i < 0 || j < 0)
    return 1e9;
  int up = arr[i][j] + minimum_path(i - 1, j, arr);
  int left = arr[i][j] + minimum_path(i, j - 1, arr);
  return min(up, left);
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> points(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> points[i][j];
    }
  }

  cout << minimum_path(n - 1, m - 1, points);
}