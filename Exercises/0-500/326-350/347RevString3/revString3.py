class Solution:
    def reverseWords(self, s: str) -> str:
        rev = list(map(lambda x: x[::-1], s.split(" ")))
        return " ".join(rev)