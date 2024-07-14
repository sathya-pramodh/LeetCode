from typing import List

# Problem Link
# https://leetcode.com/problems/combination-sum/


class Solution:
    def helper(self, candidates, target):
        if target == 0:
            return [[]]
        if target < 0:
            return None

        answers = []
        for c in candidates:
            curr = self.helper(candidates, target - c)
            if curr is not None:
                for a in curr:
                    a.append(c)
                    a.sort()
                    if a not in answers:
                        answers.append(a)
        return answers

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        for c in candidates:
            curr = self.helper(candidates, target - c)
            if curr is not None:
                for a in curr:
                    a.append(c)
                    a.sort()
                    if a not in ans:
                        ans.append(a)
        return ans
