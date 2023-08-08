/*

33. Search in Rotated Sorted Array
Medium
22.8K
1.3K
Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
[4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
Accepted
2.2M
Submissions
5.5M
Acceptance Rate
39.4%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // find rotation point by examining last item - can't be done as the numbers
    // are random (though sequential) binary search to find pivot point
    // (smallest number) [4,5,6,7,0,1,2]
    int sz = nums.size();
    int curmin = nums.front();  // 4
    int curmax = nums.back();   // 2
    if (curmax == target) return sz - 1;

    if (curmin == target) return 0;

    int mi = 0;
    int mxi = sz - 1;

    int midi = 0;
    while (mi <= mxi) {
      if (curmin > curmax) {
        int tmp = mxi;
        mxi = mi + sz;
        mi = tmp;
        int tmpv = curmin;
        curmin = curmax;
        curmax = tmpv;
      }
      int nmin = mi;
      int nmax = mxi;
      midi = ((mi + mxi) / 2)%sz;  // 3
      int midv = nums[midi];  // 7
      if (midv == target) return midv;

      if (midv < target) {
        mi = midi+1;
      }

      if (midv < target) {
        mxi = midi-1;
      }
    }
    return -1;
  }
};
