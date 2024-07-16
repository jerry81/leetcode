/*

2535. Difference Between Element Sum and Digit Sum of an Array
Easy
Topics
Companies
Hint
You are given a positive integer array nums.

The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.



Example 1:

Input: nums = [1,15,6,3]
Output: 9
Explanation:
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Explanation:
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.


Constraints:

1 <= nums.length <= 2000
1 <= nums[i] <= 2000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
126.8K
Submissions
150.2K
Acceptance Rate
84.4%

*/

impl Solution {
  pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
    let el_sum: i32 = nums.iter().sum();
    let mut d_sum: i32 = 0;
    for n in nums {
      d_sum += Solution::dsum(n);
    }
    (d_sum - el_sum).abs()
  }
  fn dsum(num: i32) -> i32 {
    num.to_string().chars().fold(0, |sm,c| {
      sm + (c as u8 - '0' as u8) as i32
    })
  }
}