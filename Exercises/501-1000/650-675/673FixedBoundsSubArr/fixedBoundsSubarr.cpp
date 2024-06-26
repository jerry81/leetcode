/*
2444. Count Subarrays With Fixed Bounds
Hard
Topics
Companies
Hint
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following
conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10
possible subarrays.


Constraints:

2 <= nums.length <= 105
1 <= nums[i], minK, maxK <= 106
Accepted
67.7K
Submissions
108.6K
Acceptance Rate
62.3%
*/

#include <vector>

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {

    long long res = 0;
    int sz = nums.size();
    for (int l = 0; l < sz; ++l) {
      int curMin = INT_MAX;
      int curMax = INT_MIN;
      // find first index where conditions are satisfied
      int startR = -1;
      int endR = -1;
      for (int r = l; r < sz; ++r) {
        curMin = min(curMin, nums[r]);
        curMax = max(curMax, nums[r]);
        if (curMin == minK && curMax == maxK) {
          if (startR < 0) startR = r;
        } else {
          if (startR >= l) {
            endR = r - 1;
            break;
          }
        }
      }
      if (startR >= l) {
        endR = endR < 0 ? sz - 1 : endR;
        res += (long long)(endR - startR + 1);
      }
    }
    return res;
    // 2 ptr
  }
};
