class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int N = nums.size();
        if (N == 1)
            return nums[0];
        int DP[102][2];
        DP[0] = {nums[0], 1};
        if (DP[0][0] > nums[1])
            DP[1] = {
                DP[0][0],
            } DP[1][0] = max(DP[0], nums[1]);
        for (int i = 2; i < N; i++)
            DP[i] = max(DP[i - 2] + nums[i], DP[i - 1]);
        return DP[N - 1];
    }
};