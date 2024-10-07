#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid,
         vector<vector<int>> &vis, vector<pair<int, int>> &vec,
         int row0, int col0)
{

  vis[row][col] = 1;
  vec.push_back({row - row0, col - col0});

  int m = grid.size();
  int n = grid[0].size();

  int delrow[] = {-1, 0, 1, 0};
  int delcol[] = {0, 1, 0, -1};

  for (int i = 0; i < 4; i++)
  {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];

    if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
    {
      dfs(nrow, ncol, grid, vis, vec, row0, col0);
    }
  }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
  // we use dfs for this problem.
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> vis(m, vector<int>(n, 0));

  // make set of vector of pairs.
  set<vector<pair<int, int>>> st;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      vector<pair<int, int>> vec;
      if (grid[i][j] == 1 && !vis[i][j])
      {
        dfs(i, j, grid, vis, vec, i, j);
        st.insert(vec);
      }
    }
  }
  return st.size();
}

int main()
{
}