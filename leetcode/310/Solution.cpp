#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  if (n==1) return {0}; // edge case
  vector<int> deg(n, 0); // degree
  vector<vector<int>> adj(n);
  for (auto& e : edges) {
    int v = e[0], w = e[1];
    adj[v].push_back(w);
    adj[w].push_back(v);
    deg[v]++;
    deg[w]++;
  }
  queue<int> q; 
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1)
      q.push(i);
  }
  vector<int> ans;
  int left=n;
  while (!q.empty()) {
    int qz = q.size();
    left-=qz; // how many left
    for (int i = 0; i < qz; i++) {
      int v = q.front();
      q.pop();
      if (left==0)//centers are found
        ans.push_back(v);
      for (int w : adj[v]) {
        if (--deg[w] == 1)// remove edge connecting to v
          q.push(w);
      }
    }
  }
  return ans;
}

int Solution::solve() {

}


// Optimal solution

// vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//   if(n == 1) return {0};
//   vector<pair<int,int>> connectInfo(n);
//   // Info - first : acc of vertex
//   //      - second: connect number

//   for(auto& edge : edges)
//   {
//     connectInfo[edge[0]].first += edge[1];
//     connectInfo[edge[0]].second++;
//     connectInfo[edge[1]].first += edge[0];
//     connectInfo[edge[1]].second++;
//   }

//   vector<int> NotRootVertex;
//   for(int i = 0 ; i < n ; i++)
//   {
//     if(connectInfo[i].second == 1)
//       NotRootVertex.push_back(i);
//   }
  
//   vector<int> newLeave;
//   while(n > 2)
//   {
//     n -= NotRootVertex.size();
//     newLeave.clear();
//     for(int i = 0 ; i < NotRootVertex.size() ; i++)
//     {
//       connectInfo[connectInfo[NotRootVertex[i]].first].first -= NotRootVertex[i];
//       connectInfo[connectInfo[NotRootVertex[i]].first].second--;

//       if(connectInfo[connectInfo[NotRootVertex[i]].first].second == 1)
//         newLeave.push_back(connectInfo[NotRootVertex[i]].first);
//     }
    
//     NotRootVertex = newLeave;
//   }

//   return NotRootVertex;
// }