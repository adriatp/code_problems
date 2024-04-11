#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int maxDepth(string s) {
  int act = 0, max=0;
  for (char c : s) {
    if (c == '(') act++;
    else if (c == ')') act--;
    if (act > max) max = act;
  }
  return max;
}

int Solution::solve() {
  string s = "";
  s="";
  // s="(1+(2*3)+((8)/4))+1";
  // s="(1)+((2))+(((3)))";
  int res = maxDepth(s);
  cout << res << endl;
  return 0;
}

// Optimal solution
// ListNode* reverseList(ListNode* head) {
//     ListNode *nextNode, *prevNode = NULL;
//     while (head) {
//         nextNode = head->next;
//         head->next = prevNode;
//         prevNode = head;
//         head = nextNode;
//     }
//     return prevNode;
// }