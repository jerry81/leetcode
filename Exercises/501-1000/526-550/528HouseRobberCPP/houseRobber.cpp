/*

198. House Robber
Solved
Medium
Topics
Companies
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
Seen this question in a real interview before?
1/4
Yes
No
Accepted
1.9M
Submissions
3.9M
Acceptance Rate
50.3%

*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
unordered_map<int, int> dp;
int r(int idx, vector<int>& nums, int &s) {
  if (idx >= s) return 0;

  if (dp.find(idx) != dp.end()) return dp[idx];

  return dp[idx] = max(nums[idx]+r(idx+2, nums, s), r(idx+1, nums,s));
};
public:
    int rob(vector<int>& nums) {
      int s = nums.size();
      return r(0,nums,s);
    }
};