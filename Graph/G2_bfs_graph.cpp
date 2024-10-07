#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start, int v, vector<int> adj[])
{
  vector<int> vis(v + 1, 0);
  vis[start] = 1;
  queue<int> q;
  q.push(start);
  vector<int> ans;
  while (!q.empty())
  {
    int Node = q.front();
    q.pop();
    ans.push_back(Node);

    for (auto it : adj[Node])
    {
      if (!vis[it])
      {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  return ans;
}
void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    addEdge(adj, u, v);
  }

  int startNode = 1;
  vector<int> bfsTraversal = bfs(startNode, n, adj);

  for (auto it : bfsTraversal)
    cout << it << ' ';
}