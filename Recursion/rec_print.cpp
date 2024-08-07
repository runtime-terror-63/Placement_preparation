#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void solve(int n)
{
  if (cnt == n)
    return;
  cout << cnt << endl;
  cnt++;
  solve(n);
}
int main()
{
  int n;
  cin >> n;
  solve(n);
}