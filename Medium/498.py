# 10m 40s

class Solution:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        up = True

        Y = len(mat)
        X = len(mat[0])

        total = X * Y

        result = [-1 for _ in range(total)]
        x = 0
        y = 0
        for i in range(total):
            result[i] = mat[y][x]
            if up:
                nx = x + 1
                ny = y - 1

                if nx < 0 or ny < 0 or nx >= X or ny >= Y:
                    nx = x + 1
                    ny = y
                    if nx < 0 or ny < 0 or nx >= X or ny >= Y:
                        nx = x
                        ny = y + 1
                    up = False
            else:
                nx = x - 1
                ny = y + 1

                if nx < 0 or ny < 0 or nx >= X or ny >= Y:
                    nx = x
                    ny = y + 1
                    if nx < 0 or ny < 0 or nx >= X or ny >= Y:
                        nx = x + 1
                        ny = y
                    up = True
            x = nx
            y = ny

        return result

