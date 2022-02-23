// 200. Number of Islands
// 02/24/2022 02:34	Accepted	39 ms	12.4 MB	cpp

#include <stdio.h>
#include <vector>
using namespace std;

int visited[302][302];

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

class Solution
{
public:
    int dfs(int x, int y, vector<vector<char>> &grid)
    {
        visited[y][x] = 1;
        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx < 0 || ry < 0 || rx >= M || ry >= N)
                continue;
            if (grid[ry][rx] - '0' && !visited[ry][rx])
                dfs(rx, ry, grid);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        N = grid.size();
        M = grid[0].size();
        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++)
                if (grid[y][x] - '0' && !visited[y][x])
                {
                    dfs(x, y, grid);
                    cnt++;
                }
        return cnt;
    }
};

/*
["1","1","0","0","0"],
["1","1","0","0","0"],
["0","0","1","0","0"],
["0","0","0","1","1"]
*/