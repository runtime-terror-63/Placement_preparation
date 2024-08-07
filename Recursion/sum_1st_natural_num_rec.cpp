#include <bits/stdc++.h>
using namespace std;
void solve(int n, int &sum)
{
  if (n < 1)
    return;
  solve(n - 1, sum += n);
}
int main()
{
  int n;
  cin >> n;
  int sum = 0;
  solve(n, sum);
  cout << sum << endl;
}