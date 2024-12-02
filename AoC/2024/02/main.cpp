#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> readFile(const string& filename) {
  vector<vector<int>> v_v_int;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    istringstream stream(line);
    int number;
    vector<int> v_int;
    while (stream >> number) {
      v_int.push_back(number);
    }
    v_v_int.push_back(v_int);
  }
  return v_v_int;
}

int main() {
  vector<vector<int>> levels = readFile("input.txt");
  // for (int i=0; i<levels.size(); i++) {
  //   for (int j=0; j<levels[i].size(); j++) {
  //     cout << levels[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int safes = 0;
  for (int i=0; i<levels.size(); i++) {
    int j=0;
    bool safe=true, asc=(levels[i][0]-levels[i][1] < 0);
    while (j<levels[i].size()-1 && safe) {
      int diff = levels[i][j] - levels[i][j+1];
      if (diff == 0 || (diff > 0 && asc) || (diff < 0 && !asc) || abs(diff) > 3)
        safe = false;
      j++;
    }
    if (safe) safes++;
  }
  cout << "Safes: " << safes << endl;
  return 0;
}
