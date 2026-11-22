# 5m 50s

class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"

        prev = self.countAndSay(n - 1)

        tmp = []
        for p in prev:
            if not tmp:
                tmp.append(p)
                continue

            if tmp[-1][0] == p:
                tmp[-1] = tmp[-1] + p
            else:
                tmp.append(p)

        res = ""
        for t in tmp:
            res += str(len(t)) + t[0]

        return res
