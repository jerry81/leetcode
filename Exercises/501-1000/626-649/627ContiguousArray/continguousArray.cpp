/*


525. Contiguous Array
Medium
Topics
Companies
Given a binary array nums, return the maximum length of a contiguous subarray
with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0
and 1. Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
number of 0 and 1.


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

#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    // two pointer
    int sz = nums.size();
    if (sz <= 1) return 0;
    unordered_map<int, int> score;
    score[0] = -1;

    int res = 0;
    int cur = 0;
    for (int i = 0; i < sz; ++i) {
      if (nums[i] == 0) {
        cur -= 1;

      } else {
        cur += 1;
      }
      if (score.find(cur) != score.end()) {
        res = max(res, i - score[cur]);
      } else {
          score[cur] = i;
      }

    }
    return res;
  }
};