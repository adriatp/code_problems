#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
  long long ans=0;
  int maxi=-1, mini=-1;
  int s=nums.size();
  for(int r=0, l=0; r<s; r++){
    int x=nums[r];
    if (x<minK ||x>maxK){// x exceeds the bound
      l=r+1; // move l to r+1
      continue;
    }
    if (x==maxK) maxi=r; // position for maxK
    if (x==minK) mini=r; // position for minK
    ans+=max((min(maxi, mini)-l+1),0);
  }
  return ans;
}

int Solution::solve() {
  // vector<int> nums = {1,4,2,1};
  // int k = 3;
  vector<int> nums = {28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49};
  int k=1;
  long long result = countSubarrays(nums,k);
  cout << result << endl;
  return 0;
}

// Optimal solution

// class Solution {
// public:
//     static int countBits(int n) {
//     std::bitset<32> bits(n);
//     return bits.count();
//     }

//     static bool customLess(int a, int b) {
//         int countA = countBits(a);
//         int countB = countBits(b);
//         if (countA == countB) {
//             return a < b;
//         }

//         return countA < countB;
//     }

//     std::vector<int> sortByBits(std::vector<int>& arr) {
//         std::sort(arr.begin(), arr.end(), customLess);
//         return arr;
//     }
// };