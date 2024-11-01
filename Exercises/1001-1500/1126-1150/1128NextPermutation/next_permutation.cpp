/*

31. Next Permutation
Medium
Topics
Companies
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.



Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.6M
Submissions
3.7M
Acceptance Rate
41.4%

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
/*
123 swap
132 swap reverse the substring remainder
213
231
312
321
*/
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();
      int pivot = -1;

      // Find the largest index 'pivot' such that nums[pivot] < nums[pivot + 1]
      for (int i = n - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
          pivot = i;
          break;
        }
      }

      // If no such index exists, the array is in descending order
      if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
      }

      // Find the largest index 'successor' such that nums[successor] > nums[pivot]
      for (int i = n - 1; i > pivot; --i) {
        if (nums[i] > nums[pivot]) {
          swap(nums[pivot], nums[i]);
          break;
        }
      }

      // Reverse the sequence from pivot + 1 to the end
      reverse(nums.begin() + pivot + 1, nums.end());
    }
};
};