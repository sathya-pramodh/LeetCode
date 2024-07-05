#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
  string removeDuplicateLetters(string s) {
    map<char, int> mp;
    vector<char> v;
    for (char c : s) {
      mp[c]++;
    }
    for (char c : s) {
      mp[c]--;
      if (find(v.begin(), v.end(), c) == v.end()) {
        while (v.size() != 0 && c < v[v.size() - 1] && mp[v[v.size() - 1]] > 0)
          v.pop_back();
        v.push_back(c);
      }
    }
    string res = "";
    for (char c : v)
      res += c;
    return res;
  }
};
