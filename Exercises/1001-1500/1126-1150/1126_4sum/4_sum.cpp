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
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      unordered_set<int> as_s(nums.begin(), nums.end());
      vector<int> as_v(as_s.begin(), as_s.end());
      int n = as_v.size();
      // cache pairs in map - k is long long (value) v is last occuring position
      unordered_map<long long, int> pair_sums;
      for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
          int sm = as_v[i] + as_v[j];
          if (pair_sums.find(sm) == pair_sums.end()) {
            pair_sums[sm] = j;
          } else {
            pair_sums[sm] = max(j, pair_sums[sm]);
          }
        }
      }
    }
};