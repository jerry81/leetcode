/*

300. Longest Increasing Subsequence
Medium
19.6K
376
Companies
Given an integer array nums, return the length of the longest strictly increasing
subsequence
.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

Accepted
1.5M
Submissions
2.7M
Acceptance Rate
54.1%

*/

#include <vector>


using namespace std;

class Solution {

int r(vector<int>& nums, int &sz, int prev, int idx) {
  if (idx == sz) return 0;

  int cur = nums[idx];
  if (cur <= prev) return r(nums,sz,prev, idx+1);

  return max(r(nums,sz,prev, idx+1), 1+r(nums,sz,cur,idx+1));
}
public:
    int lengthOfLIS(vector<int>& nums) {
      // try bottom up
      int sz = nums.size();
      return r(nums,sz,INT_MIN,0);
    }
};