#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int findDuplicate(vector<int>& nums) {
  set<int> freqs;
  for (int i=0; i<nums.size(); i++) {
    if (freqs.find(nums[i]) != freqs.end()) {
      return nums[i];
    }
    freqs.insert(nums[i]);
  }
  return -1;
}

int Solution::solve() {  
  vector<int> nums = {1,3,4,2,2};
  cout << findDuplicate(nums);
  return 0;
}

// Optimal solution

// static void* init = [] () {std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr); std::cin.tie(nullptr); return nullptr;} ();

// class Solution {
// public:
//     int findDuplicate(vector<int>& arr) {
//         int size = arr.size();

//         for(int i = 0; i < size; i++) {
//             int sender = std::abs(arr.at(i));
//             int &rDest = arr.at(sender);

//             if(rDest < 0) {
//                 return sender;
//             }

//             rDest *= -1;
//         }

//         return -1;
//     }
// };