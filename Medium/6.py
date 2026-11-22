class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        space = [[""] * (len(s)) for _ in range(numRows)]
        x_idx = 0
        y_idx = 0

        dx = [0, 1]
        dy = [1, -1]
        didx = 0

        for c in s:
            space[y_idx][x_idx] = c

            tx = x_idx + dx[didx]
            ty = y_idx + dy[didx]

            if not (0 <= ty < len(space)):
                didx = (didx + 1) % 2
                tx = x_idx + dx[didx]
                ty = y_idx + dy[didx]

            x_idx = tx
            y_idx = ty

        result = "".join(
            [
                "".join(s)
                for s in space
            ]
        )

        return result
