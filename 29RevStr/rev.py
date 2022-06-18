from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        temp = s.copy()
        for i,v in enumerate(temp):
          s[len(s)-i-1] = v
        """
        Do not return anything, modify s in-place instead.
        """

sol = Solution() 
s = ["h","e","l","l","o"]
Output = ["o","l","l","e","h"]
sol.reverseString(s)
print(f"expect {Output} {s}")

s = ["H","a","n","n","a","h"]
Output = ["h","a","n","n","a","H"]
sol.reverseString(s)
print(f"expect {Output} {s}")