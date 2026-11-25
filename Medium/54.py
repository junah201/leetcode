# 5m 10s

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        Y = len(matrix)
        X = len(matrix[0])
        total = X * Y
        x = 0
        y = 0
        i = 0
        result = []
        for _ in range(total):
            result.append(matrix[y][x])
            matrix[y][x] = None

            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= X or ny >= Y or matrix[ny][nx] is None:
                i = (i + 1) % 4
                nx = x + dx[i]
                ny = y + dy[i]

            x = nx
            y = ny


        return result
