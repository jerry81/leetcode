impl Solution {
  pub fn max_sub_array(nums: Vec<i32>) -> i32 {
    // Initialize current sum and maximum sum
    let mut cur = 0; // Start from 0
    let mut res = i32::MIN; // Initialize to minimum value
    for num in nums.iter() {
      cur = cur.max(0) + num; // Update current sum
      res = res.max(cur); // Update maximum sum
    }
    res
  }
}