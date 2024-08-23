#include <bits/stdc++.h>
using namespace std;

/*
Example 1:
Input:
 arr[] = {2,5,1,3,0};
Output:
 5
Explanation:
 5 is the largest element in the array.

Example2:
Input:
 arr[] = {8,10,5,7,9};
Output:
 10
Explanation:
 10 is the largest element in the array.
 */

// TC - O(NlogN)
// SC - O(N)
int largestElement(vector<int> arr, int n)
{
  sort(arr.begin(), arr.end());
  return arr[n - 1];
}

// TC - O(N)
// SC - O(1)

int largestEle(vector<int> arr, int n)
{
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > maxi)
      maxi = arr[i];
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << largestEle(arr, n);
}
