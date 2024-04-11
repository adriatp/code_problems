#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
  map<int,vector<int>> freqs;
  int left=0, right=0, max=0;
  while (right<nums.size()) {
    if (freqs[nums[right]].size() < k) {
      if (freqs.find(nums[right]) == freqs.end()) {
        freqs[nums[right]] = vector<int>();
      }
      freqs[nums[right]].push_back(nums[right]);
      right++;
    } else {
      //  I think we could change right for first pos in nums[left] but this is correct atm
      //  If not, is better not use a vector but use an int instead
      //  Anyway, this version seems to work (LC passed)
      freqs[nums[left]].erase(freqs[nums[left]].begin());
      left++;
    }
    if (right-left > max) {
      max = right-left;
    }
  }
  return max;
}

int Solution::solve() {
  // vector<int> nums = {1,2,3,1,2,3,1,2};
  // int k = 2;
  vector<int> nums = {1,2,1,2,1,2,1,2};
  int k = 1;
  // vector<int> nums = {5,5,5,5,5,5,5};
  // int k = 4;
  int a = maxSubarrayLength(nums,k);
  cout << a << endl;
  return 0;
}

// Optimal solution

// int maxSubarrayLength(vector<int>& nums, int k) {
//     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     unordered_map<int, int> mp;
//     int n = nums.size(), i = 0, j = 0, ans = 0, flag = 0;
//     while(j < n){
//         if(++mp[nums[j]] > k) flag = 1;
//         while(flag and i <= j){
//             ans = max(ans, j - i);
//             --mp[nums[i++]];
//             if(mp[nums[j]] == k) flag = 0;
//         }
//         j++;
//     }
//     ans = max(ans, j - i);
//     return ans;  