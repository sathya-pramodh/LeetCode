#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    for (int ptr1 = 0; ptr1 < s.length(); ++ptr1) {
      int curMax = 1;
      map<char, int> visited;
      visited[s[ptr1]] = true;
      for (int ptr2 = ptr1 + 1; ptr2 < s.length(); ++ptr2) {
        if (visited[s[ptr2]]) {
          break;
        }
        visited[s[ptr2]] = true;
        curMax++;
      }
      ans = max(ans, curMax);
    }
    return ans;
  }
};
