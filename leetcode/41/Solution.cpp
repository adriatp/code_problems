#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int firstMissingPositive(vector<int>& nums) {
  int n = nums.size();

  // Step 1: Move all positive numbers to the left side of the array
  int i = 0;
  while (i < n) {
    if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
      swap(nums[i], nums[nums[i] - 1]);
    } else {
      i++;
    }
  }

  // Step 2: Find the first missing positive number
  for (i = 0; i < n; i++) {
    if (nums[i] != i + 1) {
      return i + 1;
    }
  }

  // Step 3: If all positive numbers are present, the answer is n + 1
  return n + 1;
}

int Solution::solve() {
  // vector<int> nums = {1,2,0};
  // vector<int> nums = {3,4,-1,1};
  vector<int> nums = {7,8,9,11,12};
  int n = firstMissingPositive(nums);
  cout << n << endl;
  return 0;
}

// Optimal solution
// int speedUp = []
// {std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
// bool has[100002];

// int digit(char c)
// {
//     return c & 15;
// }
// bool isDigit(char c)
// {
//     return '0' <= c && c <= '9';
// }
// int init = [] {
//     std::ofstream out("user.out");
//     std::cout.rdbuf(out.rdbuf());
//     for (string s; std::getline(std::cin, s); std::cout << '\n') {
//         int n = count(s.begin(), s.end(), ',') + 3;
//         memset(has, 0, n);
//         for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
//             if (s[_i] == '-')for (_i += 2; isDigit(s[_i]); ++_i);
//             else {
//                 int v = s[_i++] & 15;
//                 while (isDigit(s[_i])) v = v * 10 + digit(s[_i++]);
//                 if (0 < v && v < n) has[v] = true;
//             }
//         }
//         for (int i = 1;; ++i)
//             if (!has[i]) {
//                 std::cout << i;
//                 break;
//             }
//     }
//     exit(0);
//     return 0;
// }();

// class Solution {
// public:
//     int firstMissingPositive(vector<int>) { return 0; }
// };