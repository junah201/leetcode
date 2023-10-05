/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        height.emplace_back(0);
        int n = height.size();
        vector<int> max_height(n + 1, 0);

        max_height[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--)
            max_height[i] = max(max_height[i + 1], height[i]);

        stack<pair<int, int>> k;

        int ans = 0;
        int last = height[0];

        for (int i = 1; i < n; i++)
        {
            int now = height[i];
            if (now < last && max_height[i + 1] > now)
            {
                k.emplace(now, last);
            }
            else
            {
                last = now;

                while (!k.empty())
                {
                    auto [mid, left] = k.top();
                    k.pop();

                    ans += min(now, left) - mid;
                }
            }
        }

        return ans;
    }
};