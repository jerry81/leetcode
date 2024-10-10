/*

Code
Testcase
Test Result
Test Result
962. Maximum Width Ramp
Medium
Topics
Companies
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.



Example 1:

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
Example 2:

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.


Constraints:

2 <= nums.length <= 5 * 104
0 <= nums[i] <= 5 * 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
58.6K
Submissions
113.4K
Acceptance Rate
51.6%
*/

#include <vector>

using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // 2 pointer
        int n = nums.size();
        int ptr1 = 0;
        int ptr2 = n-1;
        int res = 0;
        int min_so_far = INT_MAX;
        while (ptr1 < n) {
        }
        return res;
    }
};