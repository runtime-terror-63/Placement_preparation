#include <bits/stdc++.h>
using namespace std;
void solve(int i, int n)
{
  cout << "Sayan" << i << endl;
  if (i == n)
    return;
  solve(i + 1, n);
}
int main()
{
  int n;
  cin >> n;
  solve(1, n);
}