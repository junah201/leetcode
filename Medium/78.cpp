#include <vector>
using std::vector;

class Solution
{
private:
    int N;
    vector<vector<int>> ans;
    vector<int> result;

public:
    void get(int idx, int print_idx, vector<int> &nums)
    {
        if (idx >= N)
            return;

        if (idx != 0)
        {
            vector<int> temp;
            for (int i = 1; i < print_idx; i++)
                temp.push_back(result[i]);

            ans.push_back(temp);
        }

        for (int i = idx; i < N; i++)
        {
            result[print_idx] = nums[i];
            get(i, print_idx + 1, nums);
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        N = nums.size();
        ans.resize(0);
        result.resize(0);
        result.resize(N + 1);
        get(0, 1, nums);
        return ans;
    }
};