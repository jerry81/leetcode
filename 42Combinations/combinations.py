from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ret = []
        for iter in range(k):
          for i in range(1,n+1):
              for j in range(i,n+1):
                  if (j != i):
                    ret.append([i,j])
        print (f"ret is {ret}")
        return ret

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

# n choose k (aka binomial coefficient)
# n!/(k!(n-k)!)
# n choose 3 
# 4*3*2*1 = 24 / (6) = 4
# n choose 2 
# 24 / 4 = 6