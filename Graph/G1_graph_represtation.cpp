#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int adj[n + 1][m + 1];
  memset(adj, 0, sizeof(adj));
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  int n, m;
  cin >> n >> m;
  vector<int> adjc[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;

    adjc[u].push_back(v);
    adjc[v].push_back(u);
  }

  for (int i = 0; i <= n; i++)
  {
    cout << i << ": ";
    for (auto it : adj[i])
      cout << it << " ";

    cout << endl;
  }
}