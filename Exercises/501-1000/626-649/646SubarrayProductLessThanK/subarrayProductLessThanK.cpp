/*

713. Subarray Product Less Than K
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k, return the number of
contiguous subarrays where the product of all the elements in the subarray is
strictly less than k.



Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less
than k. Example 2:

Input: nums = [1,2,3], k = 0
Output: 0


Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
Seen this question in a real interview before?
1/4
Yes
No
Accepted
281.8K
Submissions
591.4K
Acceptance Rate
47.7%

*/

#include <vector>

using namespace std;

// feels like dp with 2d vector/array
// dp params are start/end index
// but dp is not necessary.
// can skip some calculations though
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int sz = nums.size();
    int res = 0;

    int starti = 0;
    while (starti < sz) {
      long long cur_prod = 1;
      int endi = starti;
      while (endi < sz) {
        cur_prod *= nums[endi];
        if (cur_prod >= k) {
          cur_prod = 1;
          break;
        } else {
          res += 1;
        }
        endi += 1;
      }

      starti += 1;
    }
    return res;
  }
};