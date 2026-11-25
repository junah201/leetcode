# 3m 33s

from collections import defaultdict

class Solution:
    def rev(self, n):
        res = 0
        while n:
            res *= 10
            res += n % 10
            n //= 10
        return res

    def countNicePairs(self, nums: list[int]) -> int:
        mat = defaultdict(int)
        ans = 0
        for idx, value in enumerate(nums):
            tmp = value - self.rev(value)
            ans += mat[tmp]
            mat[tmp] += 1

        ans %= 10**9 + 7

        return ans

# nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
# nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
