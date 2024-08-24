#include <bits/stdc++.h>
using namespace std;

// Tc - O(n2)
// Sc - O(n)
void two_sum(vector<int> &arr, int n, int target)
{
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      if (arr[i] + arr[j] == target)
      {
        ans.push_back(arr[i]);
        ans.push_back(arr[j]);
        break;
      }
    }
  }
  for (auto it : ans)
    cout << it << ' ';
}

// hashmap

void twoSum(vector<int> &arr, int n, int target)
{
  map<int, int> mpp;
  int rem = 0;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int num = arr[i];
    rem = target - num;
    if (mpp.find(rem) != mpp.end())
    {
      ans.push_back(rem);
      ans.push_back(arr[i]);
    }
    mpp[num] = i;
  }

  for (auto it : ans)
    cout << it << " ";
}

// Two pointer
void two_Sum(vector<int> arr, int n, int target)
{
  sort(arr.begin(), arr.end());
  int left = 0, right = n - 1;
  vector<int> ans;
  while (left <= right)
  {
    if (arr[left] + arr[right] == target)
    {
      ans.push_back(arr[left]);
      ans.push_back(arr[right]);
      left++;
      right--;
    }
    else if (arr[left] + arr[right] > target)
      right--;
    else
      left++;
  }

  for (auto it : ans)
    cout << it << " ";
}
int main()
{
  int n, target;
  cin >> n;
  cin >> target;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  two_Sum(arr, n, target);
}