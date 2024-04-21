#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

// Best solution from lc
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
  if (n == 1) return true;
  vector<bool> visited(n, false);
  visited[source] = true;
  bool flag = true;
  while (flag) {
    flag = false;
    for (const auto& edge : edges) {
      if (visited[edge[0]] != visited[edge[1]]) {
        visited[edge[0]] = true;
        visited[edge[1]] = true;
        flag = true;
      }
      if (visited[destination]) return true;
    }
  }
  return false;
}

int Solution::solve() {
  vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
  int n = 3, source = 0, destination = 2;
  edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
  n = 6; source = 0; destination = 5;
  edges = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
  n = 10; source = 5; destination = 9;
  cout << validPath(n,edges,source,destination) << endl;
  return 0;
}



// Time limit excedeed

// bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//   vector<set<int>> relations(n);
//   for (int i=0; i<n; i++) relations[i] = {i};
//   for (int i=0; i<edges.size(); i++) {
//     int a=edges[i][0], b=edges[i][1];
//     for (auto j : relations[a]) relations[j].insert(relations[b].begin(),relations[b].end());
//     for (auto j : relations[b]) relations[j].insert(relations[a].begin(),relations[a].end());
//   }
//   return relations[source].find(destination) != relations[source].end();
// }


