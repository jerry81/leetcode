/*

643. Maximum Average Subarray I
Easy
2.8K
232
Companies
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum
average value and return this value. Any answer with a calculation error less
than 10-5 will be accepted.



Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000


Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
Accepted
262.6K
Submissions
606.2K
Acceptance Rate
43.3%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    double ret = 0;
    double avg = 0;
    int cursum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cursum += i;

      if (i >= k) {
        cursum -= nums[i - k];
      }

      if (i >= k - 1) {
        avg = (double)cursum / (double)k;
        if (avg > ret) ret = avg;
      }
    }
    return avg;
  }
};