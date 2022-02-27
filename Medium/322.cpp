// 322. Coin Change
// 02/27/2022 23:49	Accepted	80 ms	14.5 MB	cpp

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<int> DP;
        DP.resize(amount + 1, 0);
        for (int i = 1; i <= amount; i++)
        {
            for (auto j : coins)
            {
                if (i == j)
                    DP[i] = 1;
                else if (j > amount)
                    continue;
                else if (i - j > 0 && DP[i - j])
                {
                    if (DP[i] == 0)
                        DP[i] = DP[i - j] + 1;
                    else
                        DP[i] = min(DP[i], DP[i - j] + 1);
                }
            }
        }
        if (DP[amount] == 0)
            return -1;
        return DP[amount];
    }
};