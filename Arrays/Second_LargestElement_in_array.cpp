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
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << sec_largest(arr, n);
}