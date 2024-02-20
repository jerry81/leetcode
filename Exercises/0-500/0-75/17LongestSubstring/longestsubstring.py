class Solution:
    def isUnique(self, s: str):
        as_set = list(set(s))
        return len(as_set) == len(s)

    def lengthOfLongestSubstring(self, s: str) -> int:
        # catepillar?  
        head = 0
        tail = 1 # as slice goes to tail - 1
        longest = 0
        while tail <= len(s)+1:
          sl = s[head:tail]
          # print(f"sl is {sl}")
          if self.isUnique(sl) and len(sl) > longest:
              # print(f"{sl} is unique")
              # print(f"tail {tail} head {head}")
              longest = len(sl)
              # print(f"longest is {longest}")
              tail += 1
          else:
              head+=1
              next_tail = head+longest+1
              if next_tail > (len(s)+1):
                  break
              tail = next_tail
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
# optimization idea
# only test for strings longer than longest 
# can use dict for fast lookup of repeated strings.