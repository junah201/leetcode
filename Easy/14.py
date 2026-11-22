class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        for idx in range(len(strs[0])):
            for s in strs[1:]:
                try:
                    if s[idx] != strs[0][idx]:
                        return strs[0][:idx]
                except:
                    return strs[0][:idx]
        return strs[0]
