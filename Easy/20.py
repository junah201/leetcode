class Solution:
    def isValid(self, s: str) -> bool:
        parentheses = {
            "(" : ")",
            "{" : "}",
            "[" : "]"
        }

        stack = []
        for c in s:
            if c in parentheses.keys():
                stack.append(c)
            elif c in parentheses.values():
                if not stack:
                    return False
                top = stack.pop()
                if parentheses[top] != c:
                    return False
        return not stack
    