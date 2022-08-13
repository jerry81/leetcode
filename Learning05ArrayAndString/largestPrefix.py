"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
"""

from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # starting with i = 0
        # accum is empty string
        # until there is no match
        # take char i from all the strings
        # if no match return the accum
        # if match, add the character to the accum
        i = 0
        accum = ""
        while True:
          char = None
          for s in strs:
            if (len(s) - 1) <= i:
              return accum
            if char == None:
              char = s[i]
            if s[i] != char:
              return accum
          accum+=char