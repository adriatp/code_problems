#include <bits/stdc++.h>
#include "TreeNode.h"
#include "Solution.h"

using namespace std;

string moveWheel(string wheels, int wheel_pos, int jump) {
  int new_digit = (wheels[wheel_pos] - '0' + jump + 10) % 10;
  wheels[wheel_pos] = '0' + new_digit;
  return wheels;
}

int openLock(vector<string>& deadends, string target) {
  unordered_set<string> deadendSet(deadends.begin(), deadends.end());
  if (deadendSet.count("0000")) {
    return -1;
  }

  queue<pair<string, int>> queue;
  queue.push({"0000", 0});
  unordered_set<string> visited;
  visited.insert("0000");

  while (!queue.empty()) {
    auto current = queue.front();
    queue.pop();
    string currentCombination = current.first;
    int moves = current.second;
    
    if (currentCombination == target) {
      return moves;
    }
    
    for (int i = 0; i < 4; i++) {
      for (int delta : {-1, 1}) {
        int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
        string newCombination = currentCombination;
        newCombination[i] = '0' + newDigit;

        if (visited.find(newCombination) == visited.end() && deadendSet.find(newCombination) == deadendSet.end()) {
          visited.insert(newCombination);
          queue.push({newCombination, moves + 1});
        }
      }
    }
  }
  return -1;
}

int Solution::solve() {
  vector<string> deadends = {"0201","0101","0102","1212","2002"};
  string target = "0202";
  cout << openLock(deadends, target) << endl;
  return 0;
}

// Optimal solution

// //total water is trapped into the bars
// int trap(vector<int>& h) {
//   int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
//   while(l<r){
//     lmax=max(lmax,h[l]);
//     rmax=max(rmax,h[r]);
//     ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
//   }
//   return ans;
// }