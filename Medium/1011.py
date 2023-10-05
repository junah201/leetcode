from typing import List


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        sum_value = sum(weights)
        ideal_value = sum_value / days

        if days == 1:
            return sum_value

        start = int(ideal_value) - 1
        end = sum_value

        ans = sum_value

        while start <= end:
            mid = (start + end) // 2
            tcnt = 0
            tsum = 0

            for i in weights:
                if tsum + i > mid:
                    tcnt += 1
                    tsum = i

                if i > mid:
                    tcnt = days + 201
                    break

                tsum += i

            if tcnt <= days:
                end = mid - 1
                ans = min(ans, mid)
            else:
                start = mid + 1

        return ans
