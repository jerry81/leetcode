/*

1979. Find Greatest Common Divisor of Array
Easy
Topics
Companies
Hint
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.



Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
Example 2:

Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
Example 3:

Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.


Constraints:

2 <= nums.length <= 1000
1 <= nums[i] <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
126.7K
Submissions
163K
Acceptance Rate
77.7%

*/

impl Solution {
  pub fn find_gcd(nums: Vec<i32>) -> i32 {
    let mut sorted = nums.clone();
    sorted.sort();
    let lgst = sorted.last().unwrap();
    let smll = sorted.first().unwrap();

    0
  }

  fn gcd() {
  }
}