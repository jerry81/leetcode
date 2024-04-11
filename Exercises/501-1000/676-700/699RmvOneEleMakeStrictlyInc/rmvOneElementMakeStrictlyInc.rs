/*

1909. Remove One Element to Make the Array Strictly Increasing
Easy
Topics
Companies
Hint
Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).



Example 1:

Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.
Example 2:

Input: nums = [2,3,1,2]
Output: false
Explanation:
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.
Example 3:

Input: nums = [1,1,1]
Output: false
Explanation: The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.


Constraints:

2 <= nums.length <= 1000
1 <= nums[i] <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
62.1K
Submissions
228.1K
Acceptance Rate
27.2%

*/

impl Solution {
  pub fn can_be_increasing(nums: Vec<i32>) -> bool {
    let mut prev = 0;
    let sz = nums.len();
    let mut second_run: Vec<i32> = nums.clone();
    let mut third_run: Vec<i32> = nums.clone();
    let mut invalid = false;
    for i in 0..sz {
      if prev < nums[i] {
        prev = nums[i];
      } else {
        invalid = true;
        second_run.remove(i);
        third_run.remove(i-1);
        break
      }
    }
    if !invalid { return true; }
    Solution::is_increasing(&second_run) || Solution::is_increasing(&third_run)
  }

  fn is_increasing(nums: &Vec<i32>) -> bool {
    let mut prev = 0;
    for &num in nums {
      if num <= prev { return false; }

      prev = num;
    }
    true
  }
}