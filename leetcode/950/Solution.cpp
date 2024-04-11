#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
  sort(deck.begin(), deck.end());
  int n=deck.size();
  vector<int> result(n);
  deque<int> indices;
  for (int i=0; i<n; i++) indices.push_back(i);
  for (int card : deck) {
    int idx=indices.front();
    indices.pop_front();
    result[idx]=card;
    if (!indices.empty()) {
      indices.push_back(indices.front());
      indices.pop_front();
    }
  }
  return result;
}

int Solution::solve() {
  vector<int> deck = {17,13,11,2,3,5,7};
  vector<int> res = deckRevealedIncreasing(deck);
  // {2,13,3,11,5,17,7}
  for (auto i : res) cout << i << " ";
  return 0;
}

// Optimal solution

// vector<int> deckRevealedIncreasing(vector<int>& deck) {
//   int n = deck.size();
//   sort(deck.begin(), deck.end());
//   queue<int> q; // o to n-1
//   for(int i = 0; i < n; i++) {
//     q.push(i);
//   }
//   vector<int> ans(n);
//   for(int i = 0; i < n; i++) {
//     int idx = q.front();
//     q.pop();
//     // popping front and pushing it to back
//     q.push(q.front());
//     q.pop();
//     ans[idx] = deck[i];
//   }
//   return ans;
// }