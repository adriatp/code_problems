#include <bits/stdc++.h>
#include "ListNode.h"

using namespace std;

void ListNode::print() {
  ListNode *aux = this;
  while (aux != NULL) {
    cout << aux->val << " ";
    aux = aux->next;
  }
  cout << endl;
}