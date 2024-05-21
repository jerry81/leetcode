/*
78. Subsets
Medium
Topics
Companies
Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.9M
Submissions
2.4M
Acceptance Rate
77.7%
*/

#include <vector>

using namespace std;

class Solution {
vector<vector<int>> res;
 void r(int idx, vector<int> cur, vector<int>& nums, int sz) {
  if (idx == sz) {
    res.push_back(cur); return;
  };
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      int sz = nums.size();
      r(0, {}, nums, sz);
      return res;
    }
};