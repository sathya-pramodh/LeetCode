# Problem Link:
# https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/

class Solution:
    def maximumLength(self, nums, k: int) -> int:
        dp = [[0 for i in range(k)] for j in range(k)]
        ans = 0
        for n in nums:
            for nxt in range(k):
                mod = n % k
                dp[mod][nxt] = max(dp[mod][nxt], dp[nxt][mod] + 1)
                ans = max(ans, dp[mod][nxt])
        return ans
