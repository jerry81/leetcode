/*

456. 132 Pattern
Medium
6.1K
339
Companies
Given an array of n integers nums, a 132 pattern is a subsequence of three
integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k]
< nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.



Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3,
0] and [-1, 2, 0].


Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109
Accepted
185.2K
Submissions
569.9K
Acceptance Rate
32.5%

*/

#include <vector>

using namespace std;

class Solution {
  bool r(int idx, int pos, int last, vector<int>& nums, int& s) {
    if (idx >= s) return false;

    if (pos == 0) {
      // take or leave
      return r(idx + 1, pos + 1, nums[idx], nums, s) ||
             r(idx + 1, pos, last, nums, s);

    } else if (pos == 1) {
      // greater than
      int cur = nums[idx];
      bool possibilities = false;
      if (cur > last) {
        possibilities = r(idx + 1, pos + 1, nums[idx], nums, s);
      }
      return possibilities || r(idx + 1, pos, last, nums, s);
    } else {
    }
  }

 public:
  bool find132pattern(vector<int>& nums) {
    // subsequence problem
    int s = nums.size();
    return r(0, 0, -1, nums, s);
  }
};