from collections import defaultdict


class Solution:
    def fib(self,n,memo):
       if memo[n] > -1:
        return memo[n]
       if memo[n-1] and memo[n-2]:
         memo[n] = memo[n-1] + memo[n-2]
       memo[n] = self.fib(n-1, memo) + self.fib(n-2,memo)
       return memo[n]
    def climbStairs(self, n: int) -> int:
      memo=defaultdict(lambda: -1)
      memo[0] = 0 
      memo[1] = 1 
      memo[2] = 2
      return self.fib(n, memo)

s = Solution()
n = 2
a = 2
"""
1,1
2
"""

print(f"a is {a}\ns is {s.climbStairs(n)}")

n = 3
a = 3
print(f"a is {a}\ns is {s.climbStairs(n)}")
"""
1,1,1   all 1s
2,1     one 1 one 2
1,2
"""

n = 4
a = 5

print(f"a is {a}\ns is {s.climbStairs(n)}")
"""
1,1,1,1  all ones
2,1,1    one 2
1,2,1
1,1,2
2,2      two 2s 
"""
n = 5
a = 8
print(f"a is {a}\ns is {s.climbStairs(n)}")
"""
1,1,1,1,1   
2,1,1,1   one 2
1,2,1,1
1,1,2,1
1,1,1,2
2,2,1     two 2s
2,1,2
1,2,2
"""
n=6
a=13
print(f"a is {a}\ns is {s.climbStairs(n)}")
"""
1,1,1,1,1,1
2,1,1,1,1    one 2
1,2,1,1,1
1,1,2,1,1
1,1,1,2,1
1,1,1,1,2
2,2,1,1      two 2s
2,1,2,1
1,2,2,1
1,1,2,2
2,1,1,2
1,2,1,2
2,2,2         three 2s
"""
n=7
"""
1,1,1,1,1,1,1
2,1,1,1,1,1
1,2,1,1,1,1
1,1,2,1,1,1
1,1,1,2,1,1
1,1,1,1,2,1
1,1,1,1,1,2
2,2,1,1,1
2,1,2,1,1
2,1,1,2,1
2,1,1,1,2
1,2,2,1,1
1,2,1,2,1
1,2,1,1,2
1,1,2,2,1
1,1,2,1,2
1,1,1,2,2
1,2,2,2
2,1,2,2
2,2,1,2
2,2,2,1
"""
a = 21
print(f"a is {a}\ns is {s.climbStairs(n)}")

n = 10 
a = "bigger"
print(f"a is {a}\ns is {s.climbStairs(n)}")

"""
10
1,1,1,1,1,1,1,1,1,1
2,1,1,1,1,1,1,1
2,2,1,1,1,1
2,2,2,1
"""

