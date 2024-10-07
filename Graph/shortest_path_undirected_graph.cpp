#include <bits/stdc++.h>
using namespace std;

vector<int> shortedpath(vector<vector<int>> edges, int n, int m, int src)
{
  queue<pair<int, int>> q;
  vector<int> adj[n];
  vector<int> dist(n, INT_MAX);
  vector<int> vis(n, 0);

  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  q.push({src, 0});
  vis[src] = 1;
  dist[src] = 0;

  // BFS to find the shortest path
  while (!q.empty())
  {
    int node = q.front().first;
    int cnt = q.front().second;
    q.pop();

    dist[node] = cnt;

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        vis[it] = 1;
        q.push({it, cnt + 1});
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (dist[i] == INT_MAX)
      dist[i] = -1;
  }

  return dist;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;

  for (int i = 0; i < m; i++)
  {
    vector<int> temp;
    for (int j = 0; j < 2; j++)
    {
      int x;
      cin >> x;
      temp.push_back(x);
    }
    edges.push_back(temp);
  }

  int src;
  cin >> src;

  vector<int> res = shortedpath(edges, n, m, src);
  for (auto it : res)
    cout << it << " ";

  cout << "\n";
}
