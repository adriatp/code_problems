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

vector<vector<int>> remove_one(vector<int> v_int) {
  vector<vector<int>> v_v_int;
  for (size_t i = 0; i<v_int.size(); i++) {
    vector<int> tmp = v_int;
    tmp.erase(tmp.begin() + i);
    v_v_int.push_back(tmp);
  }
  return v_v_int;
}

bool is_safe(vector<int> level) {
    int j=0;
    bool safe=true, asc=(level[0]-level[1] < 0);
    while (j<level.size()-1 && safe) {
      int diff = level[j] - level[j+1];
      if (diff == 0 || (diff > 0 && asc) || (diff < 0 && !asc) || abs(diff) > 3)
        safe = false;
      j++;
    }
    return safe;
}

void part_one(vector<vector<int>> levels) {
  int safes = 0;
  for (int i=0; i<levels.size(); i++)
    if (is_safe(levels[i])) safes++;
  cout << "Safes: " << safes << endl;
}

void part_two(vector<vector<int>> levels) {
  int safes = 0;
  for (int i=0; i<levels.size(); i++) {
    if (is_safe(levels[i])) safes++;
    else {
      vector<vector<int>> sublevels = remove_one(levels[i]);
      int i=0;
      bool safe = false;
      while (i<sublevels.size() && !safe) {
        if (is_safe(sublevels[i])) {
          safe = true;
          safes++;
        }
        i++;
      }
    }
  }
  cout << "Safes: " << safes << endl;
}

int main() {
  vector<vector<int>> levels = readFile("input.txt");
  // for (int i=0; i<levels.size(); i++) {
  //   for (int j=0; j<levels[i].size(); j++) {
  //     cout << levels[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  part_one(levels);
  part_two(levels);
  return 0;
}
