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

/*
  Essence:
    like the other 2 pointer subarray problems, we can optimize by assuming in a range there are
    range number of items we can add to the result.
    we then check for ranges starting at each node.
    the key here is we are looking exact values but also care about items that go out of bounds
    - going out of bounds invalidates all arrays include that item.
    - the solution is generalized by the min/max stuff like handling a case where we have just found an out of bounds item
    and when the minK and maxK swap relative positions
*/

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {

    long long res = 0;
    int sz = nums.size();
    int minI = -1;
    int maxI = -1;
    int startI = 0;
    for (int i = 0; i < sz; ++i) {
      int cur = nums[i];
      if (cur == minK) minI = i;
      if (cur == maxK) maxI = i;

      if (cur < minK || cur > maxK) {
        minI = -1;
        maxI = -1;
        startI = i+1;
      }

      res+=max(0LL, (long long)min(minI, maxI) - startI + 1);
    }
    return res;
    // 2 ptr
  }
};