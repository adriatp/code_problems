#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> readFile(const string& filename) {
  vector<int> list1;
  vector<int> list2;
  ifstream file(filename);
  string line;
  int num1, num2;
    
  while (getline(file, line)) {
    istringstream stream(line);
    stream >> num1 >> num2;
    list1.push_back(num1);
    list2.push_back(num2);  
  }
  return {list1, list2};
}

unordered_map<int, int> count_occurrences(vector<int> v_int) {
  unordered_map<int, int> u_m_i_i;
  for (int i=0; i<v_int.size(); i++) {
    if (u_m_i_i.find(v_int[i]) == u_m_i_i.end())
      u_m_i_i[v_int[i]] = 0;
    u_m_i_i[v_int[i]]++;
  }
  return u_m_i_i;
}

int distance(vector<vector<int>> lists) {
  sort(lists[0].begin(), lists[0].end(), greater<int>());
  sort(lists[1].begin(), lists[1].end(), greater<int>());
  int sum = 0;
  for (int i=0; i<lists[0].size(); i++) {
    sum += abs(lists[0][i] - lists[1][i]);
  }
  return sum;
}

int similarity(vector<vector<int>> lists) {
  unordered_map<int, int> counter_map = count_occurrences(lists[1]);
  int score = 0;
  for (int i=0; i<lists[0].size(); i++) {
    if (counter_map.find(lists[0][i]) != counter_map.end()) {
      score += lists[0][i] * counter_map[lists[0][i]];
    }
  }
  return score;
}

int main() {
  vector<vector<int>> lists = readFile("input.txt");
  cout << "Distance:   " << distance(lists) << endl;
  cout << "Similarity: " << similarity(lists) << endl;
  return 0;
}
