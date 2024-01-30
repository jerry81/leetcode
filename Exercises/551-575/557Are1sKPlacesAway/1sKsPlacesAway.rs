/*

1437. Check If All 1's Are at Least Length K Places Away
Easy
Topics
Companies
Hint
Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.



Example 1:


Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:


Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.


Constraints:

1 <= nums.length <= 105
0 <= k <= nums.length
nums[i] is 0 or 1
Seen this question in a real interview before?
1/4
Yes
No
Accepted
74.8K
Submissions
128.9K
Acceptance Rate
58.1%

*/

impl Solution {
  pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
    let mut last_idx: i32 = -1;
    for i in 0..nums.len() {
      if nums[i] == 1 {
        let as_i32 = i as i32;
        if last_idx >= 0 {
          if (as_i32 - last_idx) <= k { return false; }
        }

        last_idx = as_i32;
      }
    }
    true
  }
}