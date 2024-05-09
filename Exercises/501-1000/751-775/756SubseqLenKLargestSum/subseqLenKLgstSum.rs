impl Solution {
  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
      let sorted = nums.clone().sort();
      let mut res = vec![];
      let sz = sorted.len();
      for i in 0..k {
        res.push(sorted[sz-i-1]);
      }
      res
  }
}