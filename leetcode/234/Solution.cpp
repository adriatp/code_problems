#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

bool isPalindrome(ListNode* head) {
  vector<int> values;
  ListNode *aux = head;
  while (aux != NULL) {
    values.push_back(aux->val);
    aux = aux->next;
  }
  bool isPalindrome = true;
  int i=0;
  while (i<values.size()/2 && isPalindrome) {
    if (values[i] != values[values.size()-1-i]) {
      isPalindrome = false;
    }
    i++;
  }
  return isPalindrome;
}

int Solution::solve() {
  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
  cout << isPalindrome(l1) << endl;
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