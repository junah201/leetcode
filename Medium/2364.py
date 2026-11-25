# 5m

from collections import defaultdict


class Solution:
    def countBadPairs(self, nums: list[int]) -> int:
        tmp = defaultdict(int)

        ans = 0
        for idx, value in enumerate(nums):
            ans += idx - tmp[idx - value]
            tmp[idx - value] += 1

        return ans
