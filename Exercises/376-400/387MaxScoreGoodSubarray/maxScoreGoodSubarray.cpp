/*

1793. Maximum Score of a Good Subarray
Hard
1.1K
35
Companies
You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.



Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.
Example 2:

Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 2 * 104
0 <= k < nums.length
Accepted
25.3K
Submissions
45.6K
Acceptance Rate
55.5%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
      // try to maximize the min val in subarray
      // try to maximize the length of the subarray
      int ptr1 = k-1;
      int ptr2 = k+1;
      int res = nums[k];
      int count = 1;
      int mn = res;
      int sz = nums.size();
      while (ptr1 >= 0 && ptr2 < sz) {
      }
      return res;
    }
};