#include <bits/stdc++.h>

using namespace std;

int solve(long long unsigned n) {
  while (n != 1) {
    cout << n << " ";
    if (n % 2 == 0) {
      n = n >> 1;
    }
    else {
      n = n*3 + 1;
    }
  }
  cout << 1;
  return 0;
}

int main() {
  long long unsigned n;
  cin >> n;
  solve(n);
  return 0;
}
