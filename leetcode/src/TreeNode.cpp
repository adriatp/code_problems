#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

// Implementación del constructor que recibe un array de enteros
TreeNode::TreeNode(const vector<int> &values) : val(0), left(nullptr), right(nullptr) {
  if (values.size() > 0) {
    val=values[0];
    vector<int> values_aux(values);
    values_aux.erase(values_aux.begin());
    vector<int> values_left = vector<int>();
    vector<int> values_right = vector<int>();
    int j=0, change=2;
    for (int i=0; i<values_aux.size(); i++) {
      if (j==change) {
        change*=2;
        j=0;
      }
      if (j<change/2) values_left.push_back(values_aux[i]);
      else if (j>=change/2) values_right.push_back(values_aux[i]);
      j++;
    }
    if (values_left.size() > 0) left = new TreeNode(values_left);
    if (values_right.size() > 0) right = new TreeNode(values_right);
  }
}

int tree_level_rec(TreeNode *node, int actual_level) {
  if (node == NULL) return actual_level;
  int level_left = tree_level_rec(node->left, actual_level+1);
  int level_right = tree_level_rec(node->right, actual_level+1);
  return max(level_left, level_right);
}

int TreeNode::tree_level() {
  return tree_level_rec(this, 0);
}

void TreeNode::print() {
  //How

  cout << " " << endl;
}