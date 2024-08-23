#include <bits/stdc++.h>
using namespace std;

/*
Example 1:
Input:
 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output:
 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation:
 All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Example 2:
Input:
 1,2,0,1,0,4,0
Output:
 1,2,1,4,0,0,0
Explanation:
 All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
*/

// TC - O(n) + O(x) + O(n-x) = O(2n)
// Sc - O(n)

void move_zero_end(vector<int> arr, int n)
{
  vector<int> temp;
  for (int i = 0; i < n; i++)
    if (arr[i] != 0)
      temp.push_back(arr[i]);

  for (int i = 0; i < temp.size(); i++)
    arr[i] = temp[i];
  for (int i = temp.size(); i < n; i++)
    arr[i] = 0;

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}


//TC - O(x) + O(n-x) = O(n)
//SC - O(n)
void move_z_end(vector<int> arr, int n)
{
  int j = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      j = i;
      break;
    }
  }

  for (int i = j + 1; i < n; i++)
  {
    if (arr[i] != 0)
    {
      swap(arr[i], arr[j]);
      j++;
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  move_zero_end(arr, n);
}
