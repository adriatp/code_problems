#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

void reorderList(ListNode* head) {
  vector<ListNode*> nodes;
  ListNode* current = head;
  while (current != NULL) {
    nodes.push_back(current);
    current = current->next;
  }
  int n = nodes.size();
  int i = 0, j = n - 1;
  while (i<j) {
    nodes[i]->next = nodes[j];
    i++;
    if (i < j) {
      nodes[j] -> next = nodes[i];
      j--;
    }
  }
  nodes[i]-> next = NULL;
}

int Solution::solve() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  reorderList(head);
  head->print();
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