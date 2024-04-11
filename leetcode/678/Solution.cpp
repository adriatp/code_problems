#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

bool checkValidString(string s) {
  int leftMin=0, leftMax=0;
  for (int i=0; i<s.length(); i++) {
    if (s[i]=='(') {
      leftMin++;
      leftMax++;
    }
    else if (s[i]==')') {
      leftMin--;
      leftMax--;
    }
    else if (s[i] == '*') {
      leftMin--;
      leftMax++;
    }
    if (leftMax<0) return false;
    if (leftMin<0) leftMin=0;
  }
  return leftMin==0;
}

int Solution::solve() {
  string s="";
  s="()";
  s="(*)";
  s="(*))";
  cout << checkValidString(s) << endl;
  return 0;
}