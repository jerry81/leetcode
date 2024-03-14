/*


Code
Testcase
Test Result
Test Result
930. Binary Subarrays With Sum
Medium
Topics
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15


Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length
Seen this question in a real interview before?
1/4
Yes
No
Accepted
106K
Submissions
186.1K
Acceptance Rate
57.0%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      vector<int> cpy(nums.begin(), nums.end());
      int res = 0;
      for (int i: cpy) {
        if (i == goal) res++;
      }
      int sz = nums.size();
      for (int len = 2; len <= sz;++ len) {
        for (int j = 0; (j+len) < sz; ++j) { // 0-3, 0-2
          int cur = cpy[j] +cpy[len-1+j];
          if (cur == goal) res+=1;

          cpy[j] = cur;
        }
      }
      return res;
    }
};