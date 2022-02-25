// 209. Minimum Size Subarray Sum
// 02/25/2022 23:01	Accepted	64 ms	10.6 MB	cpp

#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int sum = 0;
        int cnt = 0;
        int start = 0;
        int end = 0;
        int ans = 987654321;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            printf("%d : %d\n", i, nums[i]);
        }
        while (end <= len)
        {
            if (sum >= target)
            {
                printf("1\n");
                if (cnt < ans)
                    ans = cnt;
                sum -= nums[start++];
                cnt--;
            }
            else
            {
                if (end == len)
                    break;
                printf("3\n");
                sum += nums[end++];
                cnt++;
            }
        }
        if (sum == target)
            if (cnt < ans)
                ans = cnt;

        if (ans == 987654321)
            return 0;
        else
            return ans;
    }
};