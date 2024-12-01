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

int main() {
  vector<vector<int>> lists = readFile("input.txt");
  sort(lists[0].begin(), lists[0].end(), greater<int>());
  sort(lists[1].begin(), lists[1].end(), greater<int>());
  int sum = 0;
  for (int i=0; i<lists[0].size(); i++) {
    sum += abs(lists[0][i] - lists[1][i]);
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
