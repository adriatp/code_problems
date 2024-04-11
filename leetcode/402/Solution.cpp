#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

std::string removeKdigits(std::string num, int k) {
  std::stack<char> stack;
  
  for (char digit : num) {
    while (!stack.empty() && k > 0 && stack.top() > digit) {
      stack.pop();
      k--;
    }
    stack.push(digit);
  }
  
  // Remove remaining k digits from the end of the stack
  while (k > 0 && !stack.empty()) {
    stack.pop();
    k--;
  }
  
  // Construct the resulting string from the stack
  std::string result;
  while (!stack.empty()) {
    result += stack.top();
    stack.pop();
  }
  std::reverse(result.begin(), result.end()); // Reverse to get the correct order
  
  // Remove leading zeros
  size_t pos = result.find_first_not_of('0');
  result = (pos == std::string::npos) ? "0" : result.substr(pos);
  
  return result;
}

int Solution::solve() {
  // vector<int> nums = {1,4,2,1};
  // int k = 3;
  string num = "1432219";
  int k = 3;
  // num= "10200";
  // k = 1;
  // num = "10"; 
  // k = 2;
  string result = removeKdigits(num, k);
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