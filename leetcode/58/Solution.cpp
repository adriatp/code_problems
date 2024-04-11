#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int lengthOfLastWord(string s) {
  int i=s.length()-1, res=0;
  while (s[i]==' ') i--;
  while (i>=0 && s[i]!=' ') {
    res++;
    i--;
  }
  return res;
}

int Solution::solve() {
  int res = lengthOfLastWord("   fly me   to   the moon  ");
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