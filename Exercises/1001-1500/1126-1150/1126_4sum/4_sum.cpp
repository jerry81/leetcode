/*
18. 4Sum
Medium
Topics
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.1M
Submissions
3M
Acceptance Rate
36.9%

*/

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n = nums.size();
      if (n < 4) return {};
      sort(nums.begin(),nums.end());
      unordered_map<long long, int> pair_sums;

      // Cache pairs
      for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
          int sm = nums[i] + nums[j];
          pair_sums[sm] = j; // Store the last occurring position
        }
      }

      set<vector<int>> result_set;
      // Find quadruplets
      for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
          long long required_sum = target - (nums[i] + nums[j]);
          // Check if the required sum exists in pair_sums
          if (pair_sums.find(required_sum) != pair_sums.end()) {
            int k = pair_sums[required_sum];
            // Ensure k is greater than j to avoid reusing pairs
            if (k > j) {
              result_set.insert({nums[i], nums[j], nums[k], (int)(required_sum - nums[k])});
            }
          }
        }
      }
      vector<vector<int>> result(result_set.begin(), result_set.end());
      return result; // Return the result
    }
};