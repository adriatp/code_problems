#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
  vector<vector<int>> res = {};
  int n=land.size(), m=land[0].size();
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (land[i][j] == 1 && (i==0 || land[i-1][j] == 0) && (j==0 || land[i][j-1] == 0)) {
        vector<int> farm = {i,j,-1,-1};
        int ii=i, jj=j;
        while (ii < n && land[ii][j] == 1) ii++;
        while (jj < m && land[i][jj] == 1) jj++;
        farm[2] = ii-1;
        farm[3] = jj-1;
        res.push_back(farm);
      }
    }
  }
  return res;
}

int Solution::solve() {
  vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
  land = {{1, 1}, {1, 1}};
  land = {{0}};
  vector<vector<int>> res = findFarmland(land);
  for (auto i : res) {
    for (auto ii : i) {
      cout << ii << " ";
    }
    cout << endl;
  }
  return 0;
}
