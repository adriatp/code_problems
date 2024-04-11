#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

string firstPalindrome(vector<string>& words) {
  for (int i=0; i<words.size(); i++) {
    string w = words[i];
    int k=0, j=w.length()-1;
    while (k<j && w[k] == w[j]) {
      k++;
      j--;
    }
    if (k>=j) return w;
  }
  return "";
}

int Solution::solve() {
  vector<string> words = {"asdf", "ada", "xd"};
  string a = firstPalindrome(words);
  cout << a;
  return 0;
}

// Optimal solution

// #pragma GCC optimize("O3", "unroll-loops")
// class Solution {
// public:
//     string firstPalindrome(vector<string>& words) {
//         for( string& s : words){
//             int n=s.size(), n_2=n>>1;
//             bool isPal=1;
//             for(int i=0; i<n_2; i++)
//                 if(s[i]!=s[n-1-i]){
//                     isPal=0;
//                     break;
//                 }
//             if (isPal) return s;
//         }
//         return "";
//     }
// };
// auto init = []()
// { 
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();