#include <bits/stdc++.h>

using namespace std;

// DFS
void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    int v = it.first;
    if (!vis[v])
    {
      topoSort(v, adj, vis, st);
    }
  }
  st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
  vector<pair<int, int>> adj[N];
  for (int i = 0; i < M; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    int wt = edges[i][2];
    adj[u].push_back({v, wt});
  }

  int vis[N] = {0};
  stack<int> st;
  for (int i = 0; i < N; i++)
  {
    if (!vis[i])
      topoSort(i, adj, vis, st);
  }

  vector<int> dist(N);
  for (int i = 0; i < N; i++)
  {
    dist[i] = 1e9;
  }

  dist[0] = 0;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();

    for (auto it : adj[node])
    {
      int v = it.first;
      int wt = it.second;

      if (dist[node] + wt < dist[v])
      {
        dist[v] = wt + dist[node];
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    if (dist[i] == 1e9)
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
    for (int i = 0; i < 3; i++)
    {
      int c;
      cin >> c;
      temp.push_back(c);
    }
    edges.push_back(temp);
  }

  vector<int> res = shortestPath(n, m, edges);
  for (auto it : res)
    cout << it << " ";
  cout << "\n";
}