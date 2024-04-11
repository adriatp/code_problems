#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int ones_in_binary_representation(int n) {
  int ones_counter=0;
  while (n > 0) {
    ones_counter += n % 2;
    n /= 2;
  }
  cout << ones_counter << endl;
  return ones_counter;
}

vector<int> sortByBits(vector<int>& arr) {
  map<int, vector<int>> map_ones_counter;
  for (int i = 0; i < arr.size(); i++) {
    int ones_counter = ones_in_binary_representation(arr[i]);
    if (map_ones_counter.find(ones_counter) == map_ones_counter.end()) {
      map_ones_counter[ones_counter] = vector<int>();
    }
    map_ones_counter[ones_counter].push_back(arr[i]);
  }
  vector<int> result;
  for (auto it : map_ones_counter) {
    vector<int> values = it.second;
    sort(values.begin(), values.end());
    for (int i = 0; i < values.size(); i++) {
      result.push_back(values[i]);
    }
  }
  return result;
}

int Solution::solve() {  
  vector<int> arr = {0,1,2,3,4,5,6,7,8};
  vector<int> result = sortByBits(arr);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
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