#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/house-robber/

class Solution {
public:
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      if (i - 2 >= 0) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      } else if (i - 1 >= 0) {
        dp[i] = max(dp[i - 1], nums[i]);
      } else {
        dp[i] = nums[i];
      }
    }
    return dp[nums.size() - 1];
  }
};
