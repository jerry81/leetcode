/*

153. Find Minimum in Rotated Sorted Array
Medium
Topics
Companies
Hint
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.



Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.


Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2.2M
Submissions
4.3M
Acceptance Rate
52.0%

*/
impl Solution {
  pub fn find_min(nums: Vec<i32>) -> i32 {
    let mut left = 0;
    let mut right = nums.len() - 1;

    while left < right {
      let mid = left + (right - left) / 2;

      if nums[mid] > nums[right] {
        left = mid + 1; // Minimum is in the right half
      } else {
        right = mid; // Minimum is in the left half including mid
      }
    }
    nums[left] // The minimum element
  }
}

// 3 5 2

// 4 5 6 1 2 3
// 4 1 3
//

// 4 5 6 7 8 1 2
// 4 7 2
// 7 1 2
// 7 8 1 -> 1

// 11 13 15 17
// 11 13 17
