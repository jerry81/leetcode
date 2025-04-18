/*
16. 3Sum Closest
Medium
Topics
Companies
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).


Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.3M
Submissions
2.9M
Acceptance Rate
46.2%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      // brute
      int res = -1;
      int spread = INT_MAX;
      int sz = nums.size();
      for (int i = 0; i < sz-2; ++i) {
        for (int j = i+1; j < sz-1; ++j) {
          for (int k = j+1; k < sz; ++k) {
            int sm = nums[i]+nums[j]+nums[k];
            if (abs(target-sm) < spread) {
              spread = abs(target-sm);
              res = sm;
            }
          }
        }
      }
      return res;
    }
};