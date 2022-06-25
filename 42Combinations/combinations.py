from typing import List
from collections import defaultdict

class Solution:
    def nextCombination(self, n: int, k:int, cur:List):
        ret = cur.copy()
        for i in range(k):
          idx = k-1-i
          rightmost = ret[idx]
          offset = n-idx
          if (rightmost <= offset):
            ret[idx] += 1
            return ret
          else: 
            # if idx == 0:
            break
            # 1,4 
            # -> 2,3
            # 2,4
            # -> 3,4
        return None

    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        first = list(range(1,k+1))
        res.append(first)
        cur = self.nextCombination(n,k,first)
        while cur != None:
            res.append(cur)
            cur = self.nextCombination(n,k,cur) 
        return res 

sol = Solution()

n = 4
k = 2
expect = [\
  [2,4],\
  [3,4],\
  [2,3],\
  [1,2],\
  [1,3],\
  [1,4],\
]
print(f"expect {expect} \nsol is {sol.combine(n,k)}")

n = 1
k = 1
expect = [[1]]
print(f"expect {expect} {sol.combine(n,k)}")

n = 4
k = 3
expect = [\
  [1,2,3],\
  [1,2,4],\
  [1,3,4],\
  [2,3,4]
]

"""
1,2,3
1,2,4
1,3,4
2,3,4
"""

"""
1,2
1,3
1,4
2,3
2,4
3,4
"""

"""
1,2,3 bigpivot = 0, pivot = 2
1,2,4 
1,2,5 
1,2,6
1,3,4 bigpivot = 0, pivot 1
1,3,5
1,3,6
1,4,5 bigpivot 0 pivot 1
1,4,6
1,5,6
2,3,4 bigpivot 1 
"""

# n choose k (aka binomial coefficient)
# n!/(k!(n-k)!)
# n choose 3 
# 4*3*2*1 = 24 / (6) = 4
# n choose 2 
# 24 / 4 = 6