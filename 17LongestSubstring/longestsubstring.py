class Solution:
    def isUnique(self, s: str):
        as_set = list(set(s))
        return len(as_set) == len(s)

    def lengthOfLongestSubstring(self, s: str) -> int:
        # catepillar?  
        head = 0
        tail = 1 # as slice goes to tail - 1
        longest = 0
        for head in range(len(s)):
            for tail in range(1, len(s)+1):
              if tail - head < longest:
                  continue
              sl = s[head:tail]
              if self.isUnique(sl):
                  longest = tail - head 
              else:
                  break
        return longest

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

s = " "
Output = 1
print(f"expect True {sol.isUnique(s)}")
print(f"expect {Output} {sol.lengthOfLongestSubstring(s)}")

# time limit exceeded on a input case with 
# lots of repeated strings
# should optimize 