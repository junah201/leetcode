# 3m 36s

class Solution:
    def print_m(self, m):
        Y = len(m)
        X = len(m[0])

        for y in range(Y):
            print(" ".join(m[y]))
        print()


    def rotateTheBox(self, boxGrid: list[list[str]]) -> list[list[str]]:
        Y = len(boxGrid)
        X = len(boxGrid[0])
        result = [['' for _ in range(Y)] for _ in range(X)]

        self.print_m(boxGrid)

        for y in range(Y):
            for x in range(X):
                result[x][y] = boxGrid[y][x]

        self.print_m(result)
        for y in range(X):
            result[y].reverse()

        print(f"{X=} {Y=}")
        self.print_m(result)
        for y in reversed(range(X)):
            for x in range(Y):
                ty = y + 1
                while ty < X and result[ty][x] == '.' and result[ty - 1][x] == '#':
                    result[ty][x], result[ty-1][x] = result[ty-1][x], result[ty][x]
                    ty += 1

        self.print_m(result)
        return result