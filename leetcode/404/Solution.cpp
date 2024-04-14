#include <bits/stdc++.h>
#include "TreeNode.h"
#include "Solution.h"

using namespace std;

int sumOfLeftLeavesRec(TreeNode* node, bool sumAct) {
  if (node == NULL) return 0;
  int sum=0;
  if (sumAct && node->left == NULL && node->right == NULL) sum += node->val;
  sum += sumOfLeftLeavesRec(node->left,true) + sumOfLeftLeavesRec(node->right,false);
  return sum;
}

int sumOfLeftLeaves(TreeNode* root) {
  if (root == NULL) return 0;
  return sumOfLeftLeavesRec(root->left,true) + sumOfLeftLeavesRec(root->right,false);
}

int Solution::solve() {
  TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  // 24
  cout << sumOfLeftLeaves(root) << endl;
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