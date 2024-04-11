#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

ListNode* reverseList(ListNode* head) {
  ListNode* ant = NULL;
  while (head != NULL) {
    ListNode* tmp = head;
    head = head->next;
    tmp->next = ant;
    ant = tmp;
  }
  return ant;
}

int Solution::solve() {
  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode* res = reverseList(l1);
  res->print();
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