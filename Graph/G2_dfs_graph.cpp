#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &ds, vector<int> &vis)
{
  vis[node] = 1;
  ds.push_back(node);

  for (auto it : adj[node])
  {
    if (!vis[it])
      dfs(it, adj, ds, vis);
  }
}
vector<int> dfsOfGraph(int n, vector<int> adj[])
{
  vector<int> vis(n + 1, 0);
  int start = 1;
  vector<int> ls;
  dfs(start, adj, ls, vis);
  return ls;
}
void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main()
{
  int n, e;
  cin >> n >> e;
  vector<int> adj[n + 1];
  for (int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    addEdge(adj, u, v);
  }

  vector<int> res = dfsOfGraph(n, adj);

  for (auto it : res)
    cout << it << " ";
}