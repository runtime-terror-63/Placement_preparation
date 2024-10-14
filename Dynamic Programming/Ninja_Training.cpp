#include <bits/stdc++.h>
using namespace std;
int f(int day, int last, vector<vector<int>> &points)
{
  if (day == 0)
  {
    int maxi = 0;
    for (int i = 0; i <= 2; i++)
    {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++)
  {
    if (i != last)
    {
      int activity = points[day][i] + f(day - 1, i, points);
      maxi = max(maxi, activity);
    }
  }
  return maxi;
}
int ninjaTraining(int n, int m, vector<vector<int>> &points)
{
  return f(n - 1, m, points);
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> points(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> points[i][j];
    }
  }

  cout << ninjaTraining(n, m, points);
}