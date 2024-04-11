#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

bool isIsomorphic(string s, string t) {
  if (s.length() != t.length()) return false;
  int i=0;
  map<char,char> mappings_s, mappings_t;
  bool isomorphic=true;
  
  while (i<s.length() && isomorphic) {
    if (mappings_s.find(s[i]) == mappings_s.end() && mappings_t.find(t[i]) == mappings_t.end()) {
        mappings_s[s[i]] = t[i];
        mappings_t[t[i]] = s[i];
    } else if (mappings_s[s[i]] == t[i] && mappings_t[t[i]] == s[i]) {
    } else {
      isomorphic = false;
    }
    i++;
  }
  return isomorphic;
}

int Solution::solve() {
  string a="egg";
  string b="add";
  bool res = isIsomorphic(a,b);
  cout << res << endl;
  return 0;
}

// Optimal solution
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int hash[256]= {0};
//         bool istCharmapped[256]= {0};
//         for(int i=0; i<s.size(); i++){
//             if(hash[s[i]]==0 && istCharmapped[t[i]] ==0){
//                 hash[s[i]]= t[i];
//                 istCharmapped[t[i]]= true; 
//             }
//         }

//         for(int i=0; i<s.size(); i++){
//             if (char(hash[s[i]])!= t[i] ){
//                 return false; 
//             }
//         }
//         return true; 
//     }
// };