#include <bits/stdc++.h>
#include "ListNode.h"
#include "Solution.h"

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
  if (matrix.empty() || matrix[0].empty())
    return 0;

  int rows = matrix.size();
  int cols = matrix[0].size();
  vector<int> heights(cols + 1, 0); // Include an extra element for easier calculation
  int maxArea = 0;

  for (const auto& row : matrix) {
    for (int i = 0; i < cols; i++) {
      heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
    }

    // Calculate max area using stack-based method
    stack<int> stk;
    for (int i = 0; i < heights.size(); i++) {
      while (!stk.empty() && heights[i] < heights[stk.top()]) {
          int h = heights[stk.top()];
          stk.pop();
          int w = stk.empty() ? i : i - stk.top() - 1;
          maxArea = max(maxArea, h * w);
      }
      stk.push(i);
    }
  }

  return maxArea;
}
    
int Solution::solve() {
  vector<vector<char>> matrix = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'}
  };
  int res = maximalRectangle(matrix);
  cout << res << endl;
  return 0;
}

// Best solution

// int largestRectangleArea(vector < int > & histo) {
// 	stack < int > st;
// 	int maxA = 0;
// 	int n = histo.size();
// 	for (int i = 0; i <= n; i++) {
// 		while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
// 			int height = histo[st.top()];
// 			st.pop();
// 			int width;
// 			if (st.empty())
// 				width = i;
// 			else
// 				width = i - st.top() - 1;
// 			maxA = max(maxA, width * height);
// 		}
// 		st.push(i);
// 	}
// 	return maxA;
// }

// int solve(vector<vector<char>>&mat, int n, int m) {
// 	int maxArea = 0;
// 	vector<int> height(m, 0);
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			if (mat[i][j] == '1') height[j]++;
// 			else height[j] = 0;
// 		}
// 		int area = largestRectangleArea(height);
// 		maxArea = max(area, maxArea);
// 	}

// 	return maxArea;
// }


// int maximalRectangle(vector<vector<char>>& matrix) {
//   int n = matrix.size();
//   int m = matrix[0].size();

//   return solve(matrix, n, m);
// }