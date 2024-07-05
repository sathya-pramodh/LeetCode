#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/largest-number/

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> nc;
    for (int n : nums) {
      string s = to_string(n);
      nc.push_back(s);
    }
    sort(nc.begin(), nc.end(),
         [](string a, string b) { return a + b > b + a; });
    string res = "";
    bool reachedMostSignificant = false;
    for (string s : nc) {
      if (!reachedMostSignificant && s == "0")
        continue;
      if (!reachedMostSignificant && s != "0")
        reachedMostSignificant = true;
      res += s;
    }
    if (res == "" && !reachedMostSignificant)
      res = "0";
    return res;
  }
};
