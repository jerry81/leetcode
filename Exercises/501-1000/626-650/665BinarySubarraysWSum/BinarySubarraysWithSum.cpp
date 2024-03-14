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
        int n = nums.size();
        int count = 0;
        int left1 = 0, left2 = 0;
        int sum1 = 0, sum2 = 0;

        for (int right = 0; right < n; ++right) {
            sum1 += nums[right];
            while (left1 <= right && sum1 > goal)
                sum1 -= nums[left1++];
            sum2 += nums[right];
            while (left2 <= right && (sum2 >= goal || (sum2 == goal && nums[left2] == 0)))
                sum2 -= nums[left2++];
            count += left2 - left1;
        }

        return count;
    }
};