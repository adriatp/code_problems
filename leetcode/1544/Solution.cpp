#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

string makeGood(string s) {
  bool changed=true;
  while (changed) {
    int i=0;
    changed=false;
    while (i<s.length()-1) {
      if (abs(s[i]-s[i+1]) == 32) {
        if (s.length() == 2) return "";
        if (i < s.length()-2)
          s = s.substr(0,i) + s.substr(i+2);
        else 
          s = s.substr(0,i);
        changed=true;
      }
      i++;
    }
  }
  return s;
}

int Solution::solve() {
  string s = "";
  //s="leEeetcode";
  s="abBAcC";
  cout << makeGood(s) << endl;
  return 0;
}

// Better solution

// string makeGood(string s) {
//   int n = s.size();
//   for (int i = 0; i < n - 1; ) {
//     if (abs(int(s[i]) - int(s[i + 1])) == 32) {
//       // Characters are of different cases and same letter
//       s.erase(i, 2); // Remove both characters
//       if (i > 0) {
//         // Move back one step to check if the previous character and the new character can react
//         i--;
//       }
//       n -= 2; // Decrease the size of the string accordingly
//     } else {
//       // Characters do not react, move to the next pair
//       i++;
//     }
//   }
//   return s;
// }