from typing import List


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        idx = -1
        for i in range(0, len(nums), 2):
            if nums[i] == nums[i+1]:
                continue
            idx = i

        if nums[idx + 1] != nums[idx + 2]:
            return idx + 1
        return idx
