#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxArea = 0;
    int left = 0, right = height.size() - 1;
    while (left < right) {
      int minm = min(height[right], height[left]);
      maxArea = max(maxArea, minm * (right - left));
      if (height[right] < height[left]) {
        right--;
      } else {
        left++;
      }
    }
    return maxArea;
  }
};
