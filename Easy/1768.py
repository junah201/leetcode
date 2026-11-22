class Solution:
    def get_char(self, word: str, idx: int):
        if idx >= len(word):
            return ""
        return word[idx]

    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged = ""

        for idx in range(max(len(word1), len(word2))):
            merged += self.get_char(word1, idx) + self.get_char(word2, idx)

        return merged
