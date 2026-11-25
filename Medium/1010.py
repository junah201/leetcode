# 10m 10m

from collections import defaultdict
from bisect import bisect_left, bisect_right

class Solution:
    def numPairsDivisibleBy60(self, time: list[int]) -> int:
        m = defaultdict(list)

        for idx, value in enumerate(time):
            m[value % 60].append(idx)

        ans = 0

        for md in range(0, 60):
            for i in m[md]:
                opp = m[(60 - md) % 60]
                idx = bisect_right(opp, i)
                if idx == len(opp):
                    break

                ans += len(opp) - idx

        return ans