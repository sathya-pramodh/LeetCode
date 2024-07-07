#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/integer-replacement/

class Solution {
public:
  int helper(long n, map<int, int> &memo) {
    if (memo.find(n) != memo.end())
      return memo[n];
    if (n % 2) {
      int ans1 = helper(n - 1, memo) + 1;
      int ans2 = helper(n + 1, memo) + 1;
      memo[n] = min(ans1, ans2);
    } else {
      memo[n] = helper(n / 2, memo) + 1;
    }
    return memo[n];
  }
  int integerReplacement(int n) {
    map<int, int> memo = {{1, 0}};
    return helper(long(n), memo);
  }
};
