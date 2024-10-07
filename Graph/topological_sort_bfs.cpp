#include <bits/stdc++.h>
using namespace std;

vector<int> topo(vector<int> adj[], int n)
{
  queue<int> q;
  vector<int> indegree(n, 0);
  for (int i = 0; i < n; i++)
  {
    for (auto it : adj[i])
      indegree[it]++;
  }

  for (int i = 0; i < n; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  vector<int> ans;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
        q.push(it);
    }
  }
  return ans;
}
int main()
{
  int n, e;
  cin >> n >> e;
  vector<int> adj[n];
  for (int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  vector<int> res = topo(adj, n);
  for (auto it : res)
    cout << it << " ";
}