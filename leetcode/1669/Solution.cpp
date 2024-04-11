#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
  int i=0;
  ListNode *aux=list1, *ant=NULL, *last_l2=list2;
  // Search last element in list2
  while (last_l2->next != NULL) last_l2 = last_l2->next;
  // Search last element from first part of list1 (ant);
  while (i<a) {
    ant=aux;
    aux=aux->next;
    i++;
  }
  if (ant==NULL) list1 = list2;
  else ant->next = list2;
  // Search first element from last part of list1 (aux);
  while (i<b) {
    aux=aux->next;
    i++;
  }
  last_l2->next=aux->next;
  return list1;
}

int Solution::solve() {  
  int lines_input=4;
  int lines_output=1;
  int lines_for_test=lines_input+lines_output;
  for (int i=0; i<readNumberTests(); i++) {
    vector<string> lines = readLines(i*lines_for_test, i*lines_for_test+lines_for_test);
    ListNode *l1=ListNode(lines[0]), *l2=ListNode(lines[3]), *expected=ListNode(lines[4]);
    ListNode *result = mergeInBetween(l1, stoi(lines[1]), stoi(lines[2]), l2);
    if (result->toString() != expected->toString()) {
      cout << "Test " << i << " failed" << endl;
      cout << "Expected: " << expected->toString() << endl;
      cout << "Result: " << result->toString() << endl;
    }
  }
  vector<string> lines = read(5);
  ListNode *l1=ListNode(lines[0]), *l2=ListNode(lines[3]), *expected=ListNode(lines[4]);

  return 0;
}

// Optimal solution

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// auto __untie_cin = cin.tie(nullptr);
// auto __unsync_ios_stdio = ios_base::sync_with_stdio(false);

// class Solution {
// public:
//   ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
//     ListNode* curr = list1;
//     for (int i = 1; i < a; i++) {
//       curr = curr->next;
//     }

//     ListNode* tmp;
//     for (int i = a; i <= b; i++) {
//       tmp = curr->next;
//       curr->next = curr->next->next;
//       delete tmp;
//     }

//     tmp = curr->next;
//     curr->next = list2;

//     while (list2->next) {
//       list2 = list2->next;
//     }

//     list2->next = tmp;

//     return list1;
//   }
// };