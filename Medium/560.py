from collections import defaultdict


class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        tmp = [0]
        tmp.extend(nums)
        nums = tmp

        sums = [0] * len(nums)
        ans = 0

        for idx, value in enumerate(nums):
            if idx == 0:
                sums[idx] = value
            else:
                sums[idx] = sums[idx - 1] + value

        tmp = defaultdict(int)
        for i in range(len(nums)):
            ans += tmp[sums[i] - k]
            tmp[sums[i]] += 1

        return ans

# sums[i] - sums[j] = k
