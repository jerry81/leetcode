/*

55. Jump Game
Medium
Topics
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2.3M
Submissions
5.8M
Acceptance Rate
38.9%

*/
use std::collections::HashMap;

impl Solution {
  fn r(nums: &Vec<i32>, idx: usize, sz: usize, hm: &mut HashMap<usize, bool>) -> bool {
    if idx == sz-1 { return true }

    if nums[idx] >= (sz-1) as i32 { return true }

    if let Some(&result) = hm.get(&idx) {
      return result;
    }

    let max_jump = nums[idx] as usize;
    for jump in 1..=max_jump {
      if idx+jump < sz && Solution::r(nums, idx+jump, sz, hm) {
        hm.insert(idx, true);
        return true;
      }
    }

    hm.insert(idx, false);
    false
  }
  pub fn can_jump(nums: Vec<i32>) -> bool {
    let n = nums.len();
    let mut hm: HashMap<usize, bool> = HashMap::new();
    Solution::r(&nums, 0, n,  &mut hm)
  }
}