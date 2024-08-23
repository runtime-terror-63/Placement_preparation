#include <bits/stdc++.h>
using namespace std;
// TC - O(2n)
// Sc - O(1)
bool sorted_array(vector<int> arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[i])
        return false;
    }
  }
  return true;
}

// TC - O(N)
// Sc - O(1)

bool sorted_arr(vector<int> arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    if (arr[i] < arr[i - 1])
      return false;
  }
  return true;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  if (sorted_arr(arr, n))
    cout << "True";
  else
    cout << "False";
}
