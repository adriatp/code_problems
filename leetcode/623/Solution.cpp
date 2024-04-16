#include <bits/stdc++.h>
#include "TreeNode.h"
#include "Solution.h"

using namespace std;

void addOneRowRec(TreeNode* node, int val, int depth, int curr) {
  if (node == NULL) {
    // Aqui no fa res pq no hi ha node
  }
  else if (curr == depth) {
    node->left = new TreeNode(val, node->left, NULL);
    node->right  = new TreeNode(val, NULL, node->right);
  } else {
    addOneRowRec(node->left, val, depth, curr+1);
    addOneRowRec(node->right, val, depth, curr+1);
  }
}

TreeNode* addOneRow(TreeNode* root, int val, int depth) {
  if (depth == 1) return new TreeNode(val, root, NULL);
  addOneRowRec(root, val, depth, 2);
  return root;
}

int Solution::solve() {
  TreeNode *root = new TreeNode(new int[5]{4, 2, 6, 3, 1});
  root->print();
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