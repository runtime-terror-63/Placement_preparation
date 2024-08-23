/*
Example 1:
Input:
 arr[] = {1, 2, 4, 7, 7, 5};
Output:
 5
Explanation:
 5 is the sec_largest element in the array.
*/

#include <bits/stdc++.h>
using namespace std;

// TC - O(NlogN) + O(N)
// SC - O(N)

int sec_largest(vector<int> arr, int n)
{
  sort(arr.begin(), arr.end());
  int largest = arr[n - 1];
  int sec_largest = INT_MIN;
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] != largest)
    {
      sec_largest = arr[i];
      break;
    }

  return sec_largest;
}

// TC - O(N) + O(N)
// SC - O(1)
int sec_lar(vector<int> arr, int n)
{
  int Larg = INT_MIN;
  int sec_lar = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > Larg)
      Larg = arr[i];
  }

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > sec_lar && arr[i] != Larg)
      sec_lar = arr[i];
  }
  return sec_lar;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << sec_largest(arr, n);
}
