class Solution:
    def compress(self, chars: list[str]) -> int:
        tmp = []

        for c in chars:
            if not tmp:
                tmp.append(c)
                continue

            if tmp[-1][0] == c:
                tmp[-1] = tmp[-1] + c
            else:
                tmp.append(c)

        print(tmp)

        result = []
        for t in tmp:
            result.append(t[0])
            if len(t) == 1:
                continue

            result.extend(list(str(len(t))))

        chars.clear()
        chars.extend(result)

        print(chars)
        print(len(chars))

        return len(chars)
