from typing import List

# Problem link:
# https://leetcode.com/problems/beautiful-array/


class Solution:
    memo = {1: [1]}

    def beautifulArray(self, n: int) -> List[int]:
        if n not in self.memo:
            o = self.beautifulArray((n+1)//2)
            e = self.beautifulArray(n//2)
            self.memo[n] = [2*x - 1 for x in o] + [2*x for x in e]
        return self.memo[n]
