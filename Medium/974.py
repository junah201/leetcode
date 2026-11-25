class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        nums = [0] + nums
        sums = [0] * len(nums)

        for idx, value in enumerate(nums):
            if idx == 0:
                sums[idx] = value % k
            else:
                sums[idx] = (sums[idx - 1] + value) % k

        ans = 0
        tmp = [0] * (k + 1)
        for idx, s in enumerate(sums):
            ans += tmp[s]
            tmp[s] += 1

        return ans
