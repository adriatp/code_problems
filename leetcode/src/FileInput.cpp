#include <bits/stdc++.h>
#include "FileInput.h"

using namespace std;

vector<string> FileInput::readAll() {
  ifstream file("tests.txt");
  if (!file.is_open()) {
    cerr << "Unable to open file\n";
  }
  string line;
  vector<string> lines;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

vector<string> FileInput::readLines(int start, int end) {
  ifstream file("tests.txt");
  if (!file.is_open()) {
    cerr << "Unable to open file\n";
  }
  string line;
  vector<string> lines;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

int FileInput::readNumberTests() {
  ifstream file("tests.txt");
  if (!file.is_open()) {
    cerr << "Unable to open file\n";
    return 1;
  }
  string line;
  getline(file, line);
  file.close();
  return stoi(line);
}