// 53. Maximum Subarray
// 02/24/2022 22:35	Accepted	248 ms	70.5 MB	cpp

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> DP;
        int size = nums.size();
        int ans = nums[0];
        DP.resize(size, 0);
        DP[0] = nums[0];
        if(DP[0] < 0) DP[0] = 0;
        for(int i=1;i<size;i++) {
            DP[i] = DP[i-1] + nums[i];
            if(DP[i] > ans) ans = DP[i];
            if(DP[i] < 0) DP[i] = 0;
        }
        return ans;
    }
};