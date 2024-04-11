#include <bits/stdc++.h>

using namespace std;

int solve(long long unsigned n) {
  long long unsigned j;
  long long unsigned sum = 0;
  for (int i=0; i<n-1; i++) {
    cin >> j;
    sum += j;
  }
  long long unsigned sum_n = ((long long unsigned) 1 + n) * ((long long unsigned) n / 2);
  if (n % 2 != 0) sum_n += ((long long unsigned) (n+1) / 2);
  cout << sum_n - sum;
  return 0;
}

int main() {
  long long unsigned n;
  cin >> n;
  solve(n);
  return 0;
}
