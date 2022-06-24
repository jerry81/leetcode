from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return 

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
print(f"expect {expect} {sol.combine(n,k)}")

n = 1
k = 1
expect = [[1]]
print(f"expect {expect} {sol.combine(n,k)}")
