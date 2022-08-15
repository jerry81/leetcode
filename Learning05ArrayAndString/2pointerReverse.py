"""
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.



Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]


Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
"""

from typing import List


class Solution:
    def reverseString(self, s: List[str]) -> None:
        for p1 in range(len(s)):
          p2 = (len(s) - p1) - 1
          if p1 >= p2:
            return s
          s[p1],s[p2] = s[p2],s[p1]