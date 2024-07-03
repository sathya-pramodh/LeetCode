#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int cur_sum = 0;
    int max_sum = -1e6;
    for (int i = 0; i < nums.size(); ++i) {
      cur_sum += nums[i];
      max_sum = max(max_sum, cur_sum);
      cur_sum = max(cur_sum, 0);
    }
    return max_sum;
  }
};
