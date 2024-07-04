# Problem link
# https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii

class Solution:
    def minOperations(self, nums) -> int:
        ans = []
        nums = nums[::-1]
        if nums[0] == 0:
            ans.append(1)
        else:
            ans.append(0)
        last = nums[0]
        for i in range(1, len(nums)):
            if nums[i] != last:
                if nums[i]:
                    ans.append(ans[i - 1])
                else:
                    ans.append(ans[i - 1] + 2)
            else:
                ans.append(ans[i - 1])
            last = nums[i]
        return ans.pop()
