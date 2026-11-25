# 17m 15s

class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        n = len(matrix)
        for y in range(n):
            for x in range(n - y - 1):
                matrix[y][x], matrix[n - x - 1][n - y - 1] = matrix[n - x - 1][n - y - 1], matrix[y][x]

        matrix.reverse()
