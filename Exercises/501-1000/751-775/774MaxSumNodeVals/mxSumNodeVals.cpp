/*

3068. Find the Maximum Sum of Node Values
Hard
Topics
Companies
Hint
There exists an undirected tree with n nodes numbered 0 to n - 1. You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
nums[u] = nums[u] XOR k
nums[v] = nums[v] XOR k
Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.



Example 1:


Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
Output: 6
Explanation: Alice can achieve the maximum sum of 6 using a single operation:
- Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, and the array nums becomes: [1,2,1] -> [2,2,2].
The total sum of values is 2 + 2 + 2 = 6.
It can be shown that 6 is the maximum achievable sum of values.
Example 2:


Input: nums = [2,3], k = 7, edges = [[0,1]]
Output: 9
Explanation: Alice can achieve the maximum sum of 9 using a single operation:
- Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and nums[1] become: 3 XOR 7 = 4, and the array nums becomes: [2,3] -> [5,4].
The total sum of values is 5 + 4 = 9.
It can be shown that 9 is the maximum achievable sum of values.
Example 3:


Input: nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
Output: 42
Explanation: The maximum achievable sum is 42 which can be achieved by Alice performing no operations.


Constraints:

2 <= n == nums.length <= 2 * 104
1 <= k <= 109
0 <= nums[i] <= 109
edges.length == n - 1
edges[i].length == 2
0 <= edges[i][0], edges[i][1] <= n - 1
The input is generated such that edges represent a valid tree.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
7.8K
Submissions
16.9K
Acceptance Rate
46.1%

*/

#include <vector>

using namespace std;

class Solution {
  vector<vector<long long>> memo;
  long long r(int idx, int even, vector<int>& nums, int k) {
    if (idx >= nums.size()) return even ? 0:INT_MIN;

    if (memo[idx][even] >= 0) return memo[idx][even];

    int nxtEven = even==1 ? 0: 1;
    // leave
    long long res = nums[idx] + r(idx+1, even, nums, k);
    // take
    res = max(res, (nums[idx] ^ k) + r(idx+1, nxtEven, nums, k));
    memo[idx][even] = res;
    return res;
  }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
      int sz = nums.size();
      memo.resize(sz, vector<long long>(2, -1));
      return r(0, 1, nums, k);
      // iterate each edge
      // but in larger trees, nodes may be updated and affect the results of new edges
      // need to know some properties of xor ?
        /*
          yes, commutativity and associativity
          - a xor b xor b = a
          - a xor b = b xor a
          - in this setup, any two nodes are "connected" and xorable independently
          - you can make a "path" to any node
            - a xor b xor (b xor c) -> a xor c
        */
      // 3 approaches
      /*
        TLE: knapsack
        1.  top down
        2.  bottom up
        3.  greedy sort
      */
    }
};