

use std::collections::HashSet;

impl Solution {
  pub fn distinct_difference_array(nums: Vec<i32>) -> Vec<i32> {
    let l = nums.len();
    let mut res: Vec<i32> = vec![];
    for i in 0..l {
      let mut pref:HashSet<i32> = HashSet::new();
      let mut suff:HashSet<i32> = HashSet::new();
      for j in 0..=i {
        pref.insert(nums[j]);
      }
      for k in i+1..l {
        suff.insert(nums[k]);
      }
      res.push((pref.len() - suff.len()) as i32);
    }
    res
  }
}