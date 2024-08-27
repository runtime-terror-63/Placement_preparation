#include <bits/stdc++.h>
using namespace std;
//TC - O(N*N!);
//SC - O(1)
void nxt_permutaion(vector<int> arr, int n)
{
  next_permutation(arr.begin(), arr.end());
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

//TC - O(3n)
//SC - O(1)

void nextPermutation(vector<int> &nums)
{
  int ind = -1;
  for (int i = nums.size() - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      ind = i;
      break;
    }
  }
  if (ind == -1)
  {
    reverse(nums.begin(), nums.end());
    return;
  }
  for (int i = nums.size() - 1; i > ind; i--)
  {
    if (nums[i] > nums[ind])
    {
      swap(nums[i], nums[ind]);
      break;
    }
  }

  reverse(nums.begin() + ind + 1, nums.end());
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  nxt_permutaion(arr, n);
}
