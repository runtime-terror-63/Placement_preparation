#include <bits/stdc++.h>
using namespace std;
vector<int> leaderArray(vector<int> arr, int n)
{
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    bool leader = true;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] < arr[j])
      {
        leader = false;
        break;
      }
    }
    if (leader == true)
      ans.push_back(arr[i]);
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<int> res = leaderArray(arr, n);
  for (auto it : res)
    cout << it << " ";
}