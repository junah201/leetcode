class Solution:
    def get_range(self, start, before):
        if start == before:
            return f"{start}"
        return f"{start}->{before}"

    def summaryRanges(self, nums: list[int]) -> list[str]:
        result = []

        if not nums:
            return result

        start = nums[0]
        before = nums[0]
        for num in nums[1:]:
            if before + 1 == num:
                before = num
                continue
            else:
                result.append(self.get_range(start, before))
                start = num
                before = num

        result.append(self.get_range(start, before))
        return result
