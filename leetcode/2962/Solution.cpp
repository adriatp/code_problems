#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
  long long int max_num = *max_element(nums.begin(),nums.end());
  long long int left = 0, right = 0, ans = 0, count = 0;
  while(right<nums.size()){
    if(nums[right] == max_num)count++;
    while(count>=k){
      if(nums[left]==max_num)count--;
      left++;
      ans += nums.size()-right;
    }    
    right++;
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