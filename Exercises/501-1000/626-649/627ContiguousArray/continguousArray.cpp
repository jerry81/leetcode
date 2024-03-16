/*


525. Contiguous Array
Medium
Topics
Companies
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
340.3K
Submissions
722.8K
Acceptance Rate
47.1%

*/

#include <vector>

using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      // two pointer
      if (nums.size() <= 1) return 0;

      int net = 0;
      int res = 0;
      vector<vector<int>> dp;
      int sz = nums.size();
      for (int ptr1 = 0; ptr1 < sz - 1; ++ptr1) {
        int tally = nums[ptr1] == 0 ? -1 : 1;
        for (int ptr2 = ptr1+1; ptr2 < sz; ++ptr2) {
          tally += nums[ptr2] == 0 ? -1 : 1;
          dp[ptr1][ptr2] = tally;
          int rng = ptr2 - ptr1;
          res = max(rng, res);
        }
      }
      return res;
    }
};