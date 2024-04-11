#pragma once

#include <bits/stdc++.h>

using namespace std;

class FileInput {
public:
  vector<string> readAll();
  vector<string> readLines(int start, int end);
  int readNumberTests();
};