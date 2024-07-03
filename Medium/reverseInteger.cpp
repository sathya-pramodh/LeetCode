#include <bits/stdc++.h>
using namespace std;

// Problem Link:
// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
  int reverse(int x) {
    long xc = abs(x);
    long sign = (x < 0) ? -1 : 1;
    long rev = 0;
    while (xc > 0) {
      rev = rev * 10 + (xc % 10);
      xc /= 10;
    }
    if (rev % (long)pow(2, 31) != rev)
      return 0;
    return sign * rev;
  }
};
