class Solution:
    def isUnique(self, s: str):
        as_set = list(set(s))
        return len(as_set) == len(s)

    def lengthOfLongestSubstring(self, s: str) -> int:
        return 

sol = Solution()

# test isUnique
s = "abc"
print(f"expect True {sol.isUnique(s)}")
s = "bbc"
print(f"expect False {sol.isUnique(s)}")

s = "abcabcbb"
Output = 3
print(f"expect {Output} {sol.lengthOfLongestSubstring(s)}")

s = "bbbbb"
Output = 1
print(f"expect {Output} {sol.lengthOfLongestSubstring(s)}")

s = "pwwkew"
Output = 3
print(f"expect {Output} {sol.lengthOfLongestSubstring(s)}")