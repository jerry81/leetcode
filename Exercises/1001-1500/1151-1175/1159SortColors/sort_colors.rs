/*

75. Sort Colors
Medium
Topics
Companies
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]


Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


Follow up: Could you come up with a one-pass algorithm using only constant extra space?


Seen this question in a real interview before?
1/5
Yes
No
Accepted
2.5M
Submissions
3.8M
Acceptance Rate
65.5%

*/

impl Solution {
  pub fn sort_colors(nums: &mut Vec<i32>) {
    // count and replace
    let mut z = 0;
    let mut o = 0;
    let mut t = 0;
    for i in nums.iter() {
      match i {
        0 => {
          z+=1;
        }
        1 => {
          o+=1;
        }
        2 => {
          t+=1;
        }
        _ => {}
      }
    }
    let mut idx: usize = 0;
    for i in 0..z {
        nums[idx] = 0;
        idx+=1;
    }
    for i in 0..o {
        nums[idx] = 1;
        idx+=1;
    }
    for i in 0..t {
        nums[idx] = 2;
        idx+=1;
    }
    // one-pass with constant extra space: three pointers!
  }
}