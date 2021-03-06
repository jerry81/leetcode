class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if s  == s[::-1]:
            return 1
        return 2

sol = Solution()


s = "ababa"
out = 1
print(f"expect {out} {sol.removePalindromeSub(s)}")
s = "abb"
out = 2
print(f"expect {out} {sol.removePalindromeSub(s)}")
s = "baabb"
out = 2
print(f"expect {out} {sol.removePalindromeSub(s)}")
