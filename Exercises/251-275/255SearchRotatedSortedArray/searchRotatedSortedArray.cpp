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
    // (smallest number) [4,5,6,7,0,1,2] // both 4 and 2 greater than target ...
    // 4-7 no
    // 2-7 no
    // 7-2 yes
    // min = mid+1 max = max-1
    // mid (7) greater than target
    // min > max
    // mid+1 to 2
    int sz = nums.size();

    int mi = 0;
    int mxi = sz - 1;

    int midi = 0;
    // get pivot
    int pivot = -1;
    int minv = INT_MAX;
    while (mi <= mxi) {
      if (mi == mxi) {
        if (nums[mi] < minv) {
          pivot = mi;
          break;
        }
      }

      int curmax = nums[mxi];
      int curmin = nums[mi];

      if (curmax < minv) {
        minv = curmax;
        pivot = mxi;
      }

      if (curmin < minv) {
        minv = curmin;
        pivot = mi;
      }

      midi = mi + mxi / 2;

      int curmid = nums[midi];

      if (curmid < minv) {
        minv = curmid;
        pivot = curmid;
      }

      if (curmid < curmax) {
        if (curmin < curmid) {
          pivot = curmin;
          break;
        } else {
          // 4 0 1 2 3
          mi += 1;
          mxi = midi-1;

          continue;
        }
      } else {
        mi = midi+1;
        mxi-=1;
      }
      // nums = [4,5,6,7,0,1,2], target = 3
      // minv, midv, maxv, tgt
      // 4, 7, 2, 0 - all greater than target, maxv < min, maxv < midv
      // 7 to 2 (midi+1 to mxi)
      // 4, 7, 2, 3
      // target between maxv and minv
      // 2 to 4 (mxi+1 to mi)
      // cleanup - check equal for stopping condition
      // reset min and max
      // [4,5,6,7,0,1,2] target 6
      // 4,7,2,6
      // between minv and midv
      // 4 to 7
      // mi to midi-1
      // [0,1,2,3,4,5,6,7] target 5
      //  0, 4, 7, 5
      // 4 to 7
      // between midv and maxv
      // midi + 1 to mxi

    }
    cout << "pivot is " << pivot << endl;
    return -1;
  }
};


// find pivot
// [4,5,6,7,0,1,2]
// 7 2 (0 2)
// winner 0
// [7,0,1,2,4,5,6]
// 7,2
// 7,1
// 7,0
