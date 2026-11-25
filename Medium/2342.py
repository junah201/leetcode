class Solution:
    def get_sum(self, num):
        ans = 0
        for i in list(str(num)):
            ans += int(i)
        return ans

    def maximumSum(self, nums: list[int]) -> int:
        tmp = {}
        ans = -1

        for num in nums:
            s = self.get_sum(num)
            if tmp.get(s, None) is None:
                tmp[s] = num
            else:
                ans = max(ans, tmp[s] + num)
                tmp[s] = max(tmp[s], num)

        return ans
