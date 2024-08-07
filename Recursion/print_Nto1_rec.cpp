#include <bits/stdc++.h>
using namespace std;
void solve(int i, int n)
{
  if (i < 1)
    return;
  cout << i << endl;
  solve(i - 1, n);
}
int main()
{
  int n;
  cin >> n;
  solve(n, n);
}