#include <bits/stdc++.h>
using namespace std;
void union_two_sorted_array(vector<int> arr1, vector<int> arr2, int n, int m)
{
  set<int> st;
  for (int i = 0; i < n; i++)
    st.insert(arr1[i]);
  for (int j = 0; j < m; j++)
    st.insert(arr2[j]);
  vector<int> temp;
  for (auto it : st)
    temp.push_back(it);

  for (int i = 0; i < temp.size(); i++)
    cout << temp[i] << " ";
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n), arr2(m);
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  for (int j = 0; j < m; j++)
    cin >> arr2[j];
  union_two_sorted_array(arr1, arr2, n, m);
}
