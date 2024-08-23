#include <bits/stdc++.h>
using namespace std;

// TC - O(n2)
// Sc - O(n)
void intersection_two_sorted_array(vector<int> arr1, vector<int> arr2, int n, int m)
{
  vector<int> ans;
  vector<int> visi(arr2.size(), 0);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr1[i] == arr2[j] && visi[j] == 0)
      {
        ans.push_back(arr2[j]);
        visi[j] = 1;
        break;
      }
      else if (arr1[i] < arr2[j])
        break;
    }
  }

  for (auto it : ans)
    cout << it << " ";
}
/* TWO POINTER APPROCH

*/
void intersection_sorted_array(vector<int> arr1, vector<int> arr2, int n, int m)
{
  int i = 0;
  int j = 0;
  vector<int> ans;
  while (i < n && j < m)
  {
    if (arr1[i] < arr2[j])
      i++;
    else if (arr1[i] > arr2[j])
      j++;
    else
    {
      ans.push_back(arr2[j]);
      i++;
      j++;
    }
  }

  for (auto it : ans)
    cout << it << " ";
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
  intersection_sorted_array(arr1, arr2, n, m);
}