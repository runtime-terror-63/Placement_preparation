#include <bits/stdc++.h>
using namespace std;
// TC = O(d) + O(n-d) + O(d) = O(n+d)
// sc = O(d)
void leftRoate(vector<int> arr, int n, int d)
{
  d %= n;
  int temp[d];
  for (int i = 0; i < d; i++)
    temp[i] = arr[i];
  for (int i = d; i < n; i++)
    arr[i - d] = arr[i];
  for (int i = n - d; i < n; i++)
    arr[i] = temp[i - (n - d)];

  for (int i = 0; i < n; i++)
    cout << arr[i];
}

//TC - O(2n)
//Sc - O(1)

void left_rotate(vector<int> arr, int n, int d)
{
  d %= n;
  reverse(arr.begin(), arr.begin() + d); // O(d)
  reverse(arr.begin() + d, arr.end());  // O(n-d) 
  reverse(arr.begin(), arr.end());    // O(n)

  for (int i = 0; i < n; i++)
    cout << arr[i];
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int d;
  cin >> d;
  left_rotate(arr, n, d);
}
