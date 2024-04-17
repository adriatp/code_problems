#include <bits/stdc++.h>
#include "TreeNode.h"
#include "Solution.h"

using namespace std;

string smallestFromLeafRec(TreeNode* node, string current) {
  if (node == NULL) return current;
  if (node->left == NULL) return smallestFromLeafRec(node->right, char(node->val + int('a')) + current);
  else if (node->right == NULL) return smallestFromLeafRec(node->left, char(node->val + int('a')) + current);
  string left = smallestFromLeafRec(node->left, char(node->val + int('a')) + current);
  string right = smallestFromLeafRec(node->right, char(node->val + int('a')) + current);
  return (left < right) ? left : right;
}

string smallestFromLeaf(TreeNode* root) {
  string aux = ""; 
  if (root->left == NULL) return smallestFromLeafRec(root->right, char(root->val + int('a')) + aux);
  else if (root->right == NULL) return smallestFromLeafRec(root->left, char(root->val + int('a')) + aux);
  string left = smallestFromLeafRec(root->left, char(root->val + int('a')) + aux);
  string right = smallestFromLeafRec(root->right, char(root->val + int('a')) + aux);
  return (left < right) ? left : right;
}

int Solution::solve() {
  TreeNode *root = new TreeNode(vector<int>({0,1,2,3,4,5,6}));
  string res = smallestFromLeaf(root);
  cout << res << endl;
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