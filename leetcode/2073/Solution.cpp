#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
  int time=0;
  queue<int> q;
  queue<int> q_positions;
  for (int t : tickets) q.push(t);
  for (int i=0; i<tickets.size(); i++) q_positions.push(i);
  while(true) {
    if (q_positions.front() == k && q.front() == 1) {
      break;
    }
    if (q.front()>1) {
      q.push(q.front()-1);
      q_positions.push(q_positions.front());
    }
    q.pop();
    q_positions.pop();
    time++;
  }
  return time+1;
}

int Solution::solve() {
  vector<int> tickets = {2,3,2};
  int k=2;
  //6
  cout << timeRequiredToBuy(tickets, k) << endl;
  tickets={5,1,1,1};
  k=0;
  //8
  cout << timeRequiredToBuy(tickets, k) << endl;
  return 0;
}

// Optimal solution

// int timeRequiredToBuy(vector<int>& ts, int k) {
//   int res = 0, target = ts[k];
//   // parsing the queue up to k, included
//   for (int i = 0; i <= k; i++) {
//     // getting the minimum between the current value and target
//     res += min(ts[i], target);
//   }
//   // parsing the queue up from  k, excluded
//   target--;
//   for (int i = k + 1, lmt = ts.size(); i < lmt; i++) {
//     // getting the minimum between the current value and target
//     res += min(ts[i], target);
//   }
//   return res;
// }
