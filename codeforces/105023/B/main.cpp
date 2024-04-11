#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, q;
  string s;
  cin >> n >> q;
  getline(cin, s);
  getline(cin, s);
  // List of empty positions
  vector<int> empty_positions;
  for (int i=0; i<s.length(); i++) {
    if (s[i] == '.') {
      empty_positions.push_back(i);
    }
  }
  // List of stacked empty positions
  vector<int> stacked_empty_positions;
  int stacked=0;
  for (int i=0; i<s.length(); i++) {
    if (s[i] == '.') stacked++;
    stacked_empty_positions.push_back(stacked);
  }

  // Answer for each q
  for (int i=0; i<q; i++) {
    int j;
    cin >> j;
    int left=0, right=j-1, max=0;
    while (right < s.length()) {
      int dif = stacked_empty_positions[right] - stacked_empty_positions[left];
      if (s[left] == '.') dif++;
      if (dif > max) max = dif;
      left++;
      right++;
    }
    cout << n-empty_positions.size() + max << endl;
  }
  return 0;
}