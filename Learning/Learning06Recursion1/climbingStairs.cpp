/*

Climbing Stairs

Solution
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

Hint: To reach nth step, what could have been your previous steps? (Think about the step sizes)

*/
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
unordered_map<int,int> lookup;
public:
    Solution() {
      lookup[0] = 0;
      lookup[1] = 1;
      lookup[2] = 1;
    }

    int climbStairs(int n) {
      if (lookup.find(n) != lookup.end()) return lookup[n];

      lookup[n] = min(1 + climbStairs(n-1), 1+ climbStairs(n-2));
      return lookup[n];
    }
};