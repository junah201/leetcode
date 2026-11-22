# 12m 12s

class Solution:
    def format(self, words, maxWidth: int) -> str:
        if len(words) == 1:
            return words[0] + " " * (maxWidth - len(words[0]))

        남는공간 = maxWidth - sum([len(w) for w in words])
        필요한공간의개수 = len(words) - 1
        최소공간 = 남는공간 // 필요한공간의개수
        최대공간개수 = 남는공간 - (최소공간 * 필요한공간의개수)

        result = ""
        for w in words:
            result += w
            result += " " * 최소공간
            if 최대공간개수:
                result += " "
                최대공간개수 -= 1

        return result.strip()

    def format_last(self, words, maxWidth):
        tmp = " ".join(words)
        return tmp + " " * (maxWidth - len(tmp))


    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        result = []
        tmp = []
        cnt = 0

        for word in words:
            if cnt + len(word) <= maxWidth:
                tmp.append(word)
                cnt += 1 + len(word)
            else:
                result.append(self.format(tmp, maxWidth))
                tmp = [word]
                cnt = len(word) + 1

        result.append(self.format_last(tmp, maxWidth))

        return result


