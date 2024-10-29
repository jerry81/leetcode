/*
15. 3Sum
Medium
Topics
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
4M
Submissions
11.3M
Acceptance Rate
35.6%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      // number-line for fast lookup
      // since neg is present, must "normalize" the lookup table
      // rng is 2*10^5+1
      vector<int> sorted = nums;
      sort(sorted.begin(), sorted.end());
      const int MX = 2*pow(10,5)+2;
      int n = nums.size();
      vector<vector<int>> lookup = vector<vector<int>>(MX, vector<int>());
      for (int i = 0; i < n; ++i) {
        lookup[sorted[i]+pow(10,5)].push_back(i);
      }
      vector<vector<int>> res = {};
      for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
          int cur_sum = sorted[i] + sorted[j];
          int searched_idx = cur_sum*-1 + pow(10,5);
          vector<int> cand = lookup[searched_idx];
          for (int c: cand) {
            if (c > j) {
              res.push_back({i,j,-1*(i+j)});
            }
          }
        }
      }
      return res;
    }
};