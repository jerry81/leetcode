use std::sync::Mutex;

lazy_static! {
    static ref ALL: Mutex<Vec<Vec<i32>>> = Mutex::new(Vec::new());
}

impl Solution {
  fn r(idx: usize, remain: i32, sz: usize, nums: &Vec<i32>) {
  }
  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let sz = nums.len();
    r(0, k, sz, &nums);
    vec![]
  }
}