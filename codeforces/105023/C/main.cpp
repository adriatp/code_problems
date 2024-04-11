#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> freqs;
  for (int i=0; i<n; i++) {
    int aux;
    cin >> aux;
    if (freqs.find(aux) == freqs.end()) {
      freqs[aux] = 1;
    } else {
      freqs[aux]++;
    }
  }
  int max_level = 1;
  map<int,int> possible_verticals;
  map<int,int> pairs;
  for (auto it=freqs.begin(); it!=freqs.end(); it++) {
    max_level += it->second / 2;
    pairs[it->first] = it->second / 2;
    possible_verticals[it->first] = it->second % 2;
  }
  
  // If max_level > possible_verticals.size() then we can use more verticals
  auto rit_pairs = pairs.rbegin();
  auto rit_pv = possible_verticals.rbegin();
  int possible_verticals_count = possible_verticals.size();
  while (max_level > possible_verticals_count) {
    rit_pairs->second--;
    rit_pv->second += 2;
    possible_verticals_count += 2;
    rit_pairs++;
    rit_pv++;
  }

  // for (auto i : pairs) {
  //   cout << i.first << " " << i.second << endl;
  // }
  // for (auto i : possible_verticals) {
  //   cout << i.first << " " << i.second << endl;
  // }

  // Calculate best_value
  int i = 0, best_value = -1, current_value = 0;
  auto rit = possible_verticals.rbegin();
  while (rit != s.rend() && i < max_level) {
    best_value += rit->first;
    i++; rit++;
  }
  return best_value > 0 ? best_value : 0;
}