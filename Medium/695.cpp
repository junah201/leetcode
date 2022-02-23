// 695. Max Area of Island
// 02/24/2022 02:41	Accepted	40 ms	23.1 MB	cpp

#include <vector>
using namespace std;

int N, M, cnt;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

class Solution
{
public:
    void dfs(int x, int y, vector<vector<int>> &grid)
    {
        cnt++;
        grid[y][x] = 0;
        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx < 0 || ry < 0 || rx >= M || ry >= N)
                continue;
            if (grid[ry][rx])
                dfs(rx, ry, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int mx = 0;
        N = grid.size();
        M = grid[0].size();
        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++)
                if (grid[y][x])
                {
                    cnt = 0;
                    dfs(x, y, grid);
                    if (cnt > mx)
                        mx = cnt;
                }
        return mx;
    }
};