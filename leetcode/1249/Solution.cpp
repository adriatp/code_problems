#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

string minRemoveToMakeValid(string s) {
  // Initialize variables
  int openParenthesesCount = 0;
  vector<char> arr(s.begin(), s.end()); // Convert string to character array

  // First pass: mark excess closing parentheses with '*'
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == '(')
      openParenthesesCount++;
    else if (arr[i] == ')') {
      if (openParenthesesCount == 0)
        arr[i] = '*'; // Mark excess closing parentheses
      else
        openParenthesesCount--;
    }
  }

  // Second pass: mark excess opening parentheses from the end
  for (int i = arr.size() - 1; i >= 0; i--) {
    if (openParenthesesCount > 0 && arr[i] == '(') {
      arr[i] = '*'; // Mark excess opening parentheses
      openParenthesesCount--;
    }
  }
  
  // Filter out marked characters and store the result in a new string
  string result = "";
  for (char c : arr) {
    if (c != '*')
    result += c;
  }
  return result;
}

int Solution::solve() {
  string s="";
  s="lee(t(c)o)de)";
  s="a)b(c)d";
  s="))((";
  cout << minRemoveToMakeValid(s) << endl;
  return 0;
}