from typing import List

class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max = 0
        for a in accounts:
          tot = sum(a)
          if tot > max:
              max = tot 
        return max 

s = Solution()
r1 = s.maximumWealth([[1,2,3],[1,2,3]])
print(f"expect 6 {r1}")