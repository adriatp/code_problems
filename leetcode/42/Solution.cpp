#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int trap(vector<int>& height) {
  int n = height.size();
  if (n == 0) return 0;

  vector<int> left(n);
  vector<int> right(n);

  // Fill left array
  left[0] = height[0];
  for (int i = 1; i < n; i++) {
    left[i] = max(left[i - 1], height[i]);
  }

  // Fill right array
  right[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    right[i] = max(right[i + 1], height[i]);
  }

  // Calculate trapped water
  int trappedWater = 0;
  for (int i = 0; i < n; i++) {
    trappedWater += min(left[i], right[i]) - height[i];
  }

  return trappedWater;
}

int Solution::solve() {
  vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
  long long result = trap(height);
  cout << result << endl;
  return 0;
}

// Optimal solution

// //total water is trapped into the bars
// int trap(vector<int>& h) {
//   int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
//   while(l<r){
//     lmax=max(lmax,h[l]);
//     rmax=max(rmax,h[r]);
//     ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
//   }
//   return ans;
// }