#include <bits/stdc++.h>
using namespace std;
/*
vector<int> dijkstra(vector<vector<int>> adj[], int src, int v)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dist(v, INT_MAX);
  // min heap -> dist, node
  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty())
  {
    int node = pq.top().second;
    int dis = pq.top().first;
    pq.pop();

    for (auto it : adj[node])
    {
      int v = it[0];
      int w = it[1];

      // ralaxion step
      if (dis + w < dist[v])
      {
        dist[v] = dis + w;
        pq.push({dis + w, v});
      }
    }
  }
  return dist;
}*/
vector<int> dijkstra(vector<vector<int>> adj[], int src, int v)
{
  set<pair<int, int>> st;
  vector<int> dist(v, 1e9);
  st.insert({0, src});
  dist[src] = 0;

  while (!st.empty())
  {
    auto it = *(st.begin());
    int node = it.second;
    int dis = it.first;
    st.erase(it);

    for (auto it : adj[node])
    {
      int v = it[0];
      int w = it[1];

      // relaxion step
      if (dis + w < dist[v])
      {
        dist[v] = dis + w;
        st.insert({dis + w, v});
      }
    }
  }

  return dist;
}
int main()
{
  // Number of vertices (V) and edges (E)
  int v = 6, e = 9;

  // Adjacency list representation
  vector<vector<int>> adj[v];

  // Predefined adjacency list
  adj[0].push_back({1, 4});
  adj[0].push_back({2, 4});

  adj[1].push_back({0, 4});
  adj[1].push_back({2, 2});

  adj[2].push_back({0, 4});
  adj[2].push_back({1, 2});
  adj[2].push_back({3, 3});
  adj[2].push_back({4, 1});
  adj[2].push_back({5, 6});

  adj[3].push_back({2, 3});
  adj[3].push_back({5, 2});

  adj[4].push_back({2, 1});
  adj[4].push_back({5, 3});

  adj[5].push_back({2, 6});
  adj[5].push_back({3, 2});
  adj[5].push_back({5, 3});

  // Source node (S)
  int src = 0;

  // Call Dijkstra's algorithm
  vector<int> res = dijkstra(adj, src, v);

  // Output the shortest distances from the source node

  for (auto it : res)
    cout << it << " ";

  return 0;
}