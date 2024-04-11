#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
  vector<int> freqs(nums.size()+1,0);
  vector<int> result;
  for (int i=0; i<nums.size(); i++) {
    if (freqs[nums[i]] == 1) {
      result.push_back(nums[i]);
    }
    freqs[nums[i]]++;
  }
  return result;
}

int Solution::solve() {  
  vector<int> arr = {4,3,2,7,8,2,3,1};
  vector<int> result = findDuplicates(arr);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}

// Optimal solution

// #include <bit>
// #include <vector>

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums)
//     {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);

//         std::bitset<100001> cache;

//         std::vector<int> result;
//         for (const int& n : nums) {
//             bool duplicate = cache.test(n);

//             if (duplicate) {
//                 result.push_back(n);
//             }
//             else {
//                 cache.set(n);
//             }
//         }

//         return result;
//     }
// };