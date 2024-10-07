#include <bits/stdc++.h>
using namespace std;

void findTopo(int ind, vector<int> vis, stack<int> st, vector<int> adj[])
{
  vis[ind] = 1;
  for (auto it : adj[ind])
  {
    if (!vis[it])
      findTopo(it, vis, st, adj);
  }
  st.push(ind);
}
vector<int> topological(vector<int> adj[], int n)
{
  stack<int> st;
  vector<int> vis(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (vis[i] == 0)
      findTopo(i, vis, st, adj);
  }

  vector<int> ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
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

  vector<int> res = topological(adj, n);
  for (auto it : res)
    cout << it << ' ';
}