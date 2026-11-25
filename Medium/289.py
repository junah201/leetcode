# 6m 51s

dx = [1, -1, 0, 0, 1, 1, -1, -1]
dy = [0, 0, 1, -1, 1, -1, 1, -1]

class Solution:
    def gameOfLife(self, board: list[list[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        Y = len(board)
        X = len(board[0])

        count = [[0 for _ in range(X)] for _ in range(Y)]

        for y in range(Y):
            for x in range(X):
                for i in range(8):
                    nx = x + dx[i]
                    ny = y + dy[i]

                    if nx < 0 or ny < 0 or nx >= X or ny >= Y:
                        continue

                    count[y][x] += board[ny][nx]


        for y in range(Y):
            for x in range(X):
                if board[y][x]:
                    if count[y][x] < 2:
                        board[y][x] = 0
                    elif count[y][x] < 4:
                        board[y][x] = 1
                    else:
                        board[y][x] = 0
                else:
                    if count[y][x] == 3:
                        board[y][x] = 1
