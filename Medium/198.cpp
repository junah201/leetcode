// 198. House Robber
// 02/25/2022 21:25	Accepted	4 ms	7.7 MB	cpp

#include <vector>
#define max(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 1)
            return nums[0];
        int DP[102];
        DP[0] = nums[0];
        DP[1] = max(DP[0], nums[1]);
        for (int i = 2; i < N; i++)
            DP[i] = max(DP[i - 2] + nums[i], DP[i - 1]);
        return DP[N - 1];
    }
};