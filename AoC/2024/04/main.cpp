#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> read_matrix(const string& filename) {
  vector<vector<char>> v_v_char;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    v_v_char.push_back(std::vector<char>(line.begin(), line.end()));
  }
  return v_v_char;
}

int part_one() {
  vector<vector<char>> v_v_char = read_matrix("input.txt");

  // for (int i=0; i<v_v_char.size(); i++) {
  //   for (int j=0; j<v_v_char[i].size(); j++) {
  //     cout << v_v_char[i][j];
  //   }
  //   cout << endl;
  // } 
  int occurrences = 0;
  for (int i=0; i<v_v_char.size(); i++) {
    for (int j=0; j<v_v_char[i].size(); j++) {
      if (i<v_v_char.size()-3 && v_v_char[i+0][j+0] == 'X' && v_v_char[i+1][j+0] == 'M' && v_v_char[i+2][j+0] == 'A' && v_v_char[i+3][j+0] == 'S')
        occurrences++;
      if (i>2 && v_v_char[i+0][j+0] == 'X' && v_v_char[i-1][j+0] == 'M' && v_v_char[i-2][j+0] == 'A' && v_v_char[i-3][j+0] == 'S')
        occurrences++;
      if (j<v_v_char[i].size()-3 && v_v_char[i+0][j+0] == 'X' && v_v_char[i+0][j+1] == 'M' && v_v_char[i+0][j+2] == 'A' && v_v_char[i+0][j+3] == 'S')
        occurrences++;
      if (j>2 && v_v_char[i+0][j+0] == 'X' && v_v_char[i+0][j-1] == 'M' && v_v_char[i+0][j-2] == 'A' && v_v_char[i+0][j-3] == 'S')
        occurrences++;
      if (i<v_v_char.size()-3 && j<v_v_char[i].size()-3 && v_v_char[i+0][j+0] == 'X' && v_v_char[i+1][j+1] == 'M' && v_v_char[i+2][j+2] == 'A' && v_v_char[i+3][j+3] == 'S')
        occurrences++;
      if (i<v_v_char.size()-3 && j>2                    && v_v_char[i+0][j-0] == 'X' && v_v_char[i+1][j-1] == 'M' && v_v_char[i+2][j-2] == 'A' && v_v_char[i+3][j-3] == 'S')
        occurrences++;
      if (i>2 && j<v_v_char[i].size()-3                 && v_v_char[i-0][j+0] == 'X' && v_v_char[i-1][j+1] == 'M' && v_v_char[i-2][j+2] == 'A' && v_v_char[i-3][j+3] == 'S')
        occurrences++;
      if (i>2 && j>2                                    && v_v_char[i-0][j-0] == 'X' && v_v_char[i-1][j-1] == 'M' && v_v_char[i-2][j-2] == 'A' && v_v_char[i-3][j-3] == 'S')
        occurrences++;
    }
  }
  return occurrences;
}

int part_two() {
  vector<vector<char>> v_v_char = read_matrix("input.txt");
  int occurrences = 0;
  for (int i=1; i<v_v_char.size()-1; i++) {
    for (int j=1; j<v_v_char[i].size()-1; j++) {
      if (v_v_char[i][j] == 'A') {
        if (v_v_char[i-1][j-1] == 'S' && v_v_char[i+1][j+1] == 'M' && v_v_char[i-1][j+1] == 'S' && v_v_char[i+1][j-1] == 'M' ||
            v_v_char[i-1][j-1] == 'S' && v_v_char[i+1][j+1] == 'M' && v_v_char[i-1][j+1] == 'M' && v_v_char[i+1][j-1] == 'S' ||
            v_v_char[i-1][j-1] == 'M' && v_v_char[i+1][j+1] == 'S' && v_v_char[i-1][j+1] == 'S' && v_v_char[i+1][j-1] == 'M' ||
            v_v_char[i-1][j-1] == 'M' && v_v_char[i+1][j+1] == 'S' && v_v_char[i-1][j+1] == 'M' && v_v_char[i+1][j-1] == 'S')
        occurrences++;
      }
    }
  }
  return occurrences;
}

int main() {
  cout << part_one() << endl;
  cout << part_two() << endl;

  return 0;
}
 