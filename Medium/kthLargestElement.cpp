#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> heap; // Create a min heap
    for (int i = 0; i < k; ++i)
      heap.push(nums[i]);
    for (int i = k; i < nums.size(); ++i) {
      if (nums[i] > heap.top()) {
        heap.pop();
        heap.push(nums[i]);
      }
    }
    return heap.top();
  }
};
