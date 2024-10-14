#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int i, int j1, int j2, int row, int col)
{
  // Base case: 0
  if (j1 < 0 || j1 >= col || j2 < 0 || j2 >= col)
  {
    return -1e9;
  }

  // Base case: 1
  if (i == row - 1)
  {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  int res = 0;
  if (j1 == j2)
    res = grid[i][j1];
  else
    res = grid[i][j1] + grid[i][j2];

  vector<int> move1 = {-1, 0, 1};
  vector<int> move2 = {-1, 0, 1};

  int maxi = -1e9;
  for (auto m1 : move1)
  {
    for (auto m2 : move2)
    {
      int new1 = j1 + m1;
      int new2 = j2 + m2;
      int cherry = solve(grid, i + 1, new1, new2, row, col);
      maxi = max(maxi, cherry);
    }
  }
  return res + maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
  int row = grid.size();
  int col = grid[0].size();

  return solve(grid, 0, 0, col - 1, row, col);
}
int main()
{
  vector<vector<int>> grid1 = {
      {3, 1, 1},
      {2, 5, 1},
      {1, 5, 5},
      {2, 1, 1}};
  cout << "Maximum cherries collected (Example 1): " << cherryPickup(grid1) << endl;

  vector<vector<int>> grid2 = {
      {1, 0, 0, 0, 0, 0, 1},
      {2, 0, 0, 0, 0, 3, 0},
      {2, 0, 9, 0, 0, 0, 0},
      {0, 3, 0, 5, 4, 0, 0},
      {1, 0, 2, 3, 0, 0, 6}};
  cout << "Maximum cherries collected (Example 2): " << cherryPickup(grid2) << endl;
}