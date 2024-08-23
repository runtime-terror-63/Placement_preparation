#include <bits/stdc++.h>
using namespace std;

// Tc - O(n1logn) + O(n2logn) + O(n1+n2)
// Sc - O(n1+n2) + O(n1+n2)
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

/*  TWO POINTER APPROCH
    TC - O(n1+n2)
    Sc - O(n1+n2) for return only
 */

void union_sorted_arr_two(vector<int> arr1, vector<int> arr2, int n, int m)
{
  int i = 0;
  int j = 0;
  vector<int> unionArr;
  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      if (unionArr.size() == 0 || unionArr.back() != arr1[i])
        unionArr.push_back(arr1[i]);
      i++;
    }
    else
    {
      if (arr1[j] <= arr2[i])
      {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
          unionArr.push_back(arr2[j]);
        j++;
      }
    }
  }

  while (j < m)
  {
    if (unionArr.size() == 0 || unionArr.back() != arr2[j])
      unionArr.push_back(arr2[j]);
    j++;
  }
  while (i < n)
  {
    if (unionArr.size() == 0 || unionArr.back() != arr1[i])
      unionArr.push_back(arr1[i]);
    i++;
  }

  for (auto it : unionArr)
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
  union_sorted_arr_two(arr1, arr2, n, m);
}
