#include <bits/stdc++.h>
using namespace std;
/*
Example 1:
Input:
 N = 5, array[] = {1,2,3,4,5}
Output:
 2,3,4,5,1
Explanation:

Since all the elements in array will be shifted
toward left by one so ‘2’ will now become the
first index and and ‘1’ which was present at
first index will be shifted at last.


Example 2:
Input:
 N = 1, array[] = {3}
Output:
 3
Explanation:
 Here only element is present and so
the element at first index will be shifted to
last index which is also by the way the first index. */
// TC - O(N)
// SC - O(1)
void rotate_array(vector<int> arr, int n)
{
  int temp = arr[0];
  for (int i = 1; i < n; i++)
    arr[i - 1] = arr[i];

  arr[n - 1] = temp;

  for (int i = 0; i < n; i++)
    cout << arr[i];
}

//TC - O(N)
//SC - O(N)
void rot_array(vector<int> arr, int n)
{
  int temp[n];
  for (int i = 1; i < n; i++)
    temp[i - 1] = arr[i];

  temp[n - 1] = arr[0];
  for (int i = 0; i < n; i++)
    cout << temp[i];
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  rot_array(arr, n);
}
