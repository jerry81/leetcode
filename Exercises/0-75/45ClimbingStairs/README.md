70. Climbing Stairs
Easy

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

# note

even though we found a fibonnacci pattern here is the logical explanation behind this

CLIMBING STAIRS PROBLEM:
(This problem is very similar to Fibonacci Number

We have two choices at the start: either climb the first stair or climb the 2nd stair.

if we take one step from the ground, then the subproblem becomes: climbing the nth stair from the 1st stair.

if we take two step from the ground, then the subproblem becomes: climbing the nth stair from the 2nd stair.

So we can solve the given problem recursively by adding the results of sub-problems:
climbStairs(0, n) = climbStairs(1, n) + climbStairs(2, n)

def climbStairs(self, n: int) -> int:
		if n <= 2:
            return n
        
        dp = [0] * (n+1)
		
        dp[1] = 1
        dp[2] = 2
        
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        
        return dp[n]
Another more efficient approach could be:

def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        
        dp = [0, 1, 2]
        
        for i in range(3, n+1):
            dp[i%3] = dp[(i-1) % 3] + dp[(i-2) % 3]
        
        return dp[n % 3]
        
Feel free to ask the doubts and please upvote!(^_^)