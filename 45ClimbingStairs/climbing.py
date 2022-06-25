class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        return (self.climbStairs(n-1) - self.climbStairs(n-2)) + self.climbStairs(n-1)

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
1,1,1
2,1
1,2
"""
n = 4
a = 5
print(f"a is {a}\ns is {s.climbStairs(n)}")
"""
1,1,1,1
2,1,1
1,2,1
1,1,2
2,2
"""
n = 5
a = 8
print(f"a is {a}\ns is {s.climbStairs(n)}")
"""
1,1,1,1,1
2,1,1,1
1,2,1,1
1,1,2,1
1,1,1,2
2,2,1
2,1,2
1,2,2
"""
n=6
a=12
print(f"a is {a}\ns is {s.climbStairs(n)}")
"""
1,1,1,1,1,1
2,1,1,1,1
1,2,1,1,1
1,1,2,1,1
1,1,1,2,1
1,1,1,1,2
2,2,1,1
2,1,2,1
1,2,2,1
1,1,2,2
2,1,1,2
2,2,2
"""
print(f"a is {a}\ns is {s.climbStairs(n)}")

"""
10
1,1,1,1,1,1,1,1,1,1
2,1,1,1,1,1,1,1
2,2,1,1,1,1
2,2,2,1
"""