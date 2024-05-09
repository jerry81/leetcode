use std::sync::Mutex;

lazy_static! {
    static ref ALL: Mutex<Vec<Vec<i32>>> = Mutex::new(Vec::new());
}

impl Solution {
  fn r(cur: Vec<i32>, idx: usize, remain: i32, sz: usize, nums: &Vec<i32>) {
    if idx >= sz || remain <= 0 {
      let mut all = ALL.lock().unwrap(); // so it's a threading thing
      all.push(cur.clone());
      drop(all);
      return
    }

    Self::r(cur, idx+1, remain, sz, nums);

    let mut nxt = cur.clone();
    nxt.push(nums[idx]);
    Self::r(nxt, idx+1, remain-1, sz, nums);
  }
  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let sz = nums.len();
    Solution::r(vec![], 0, k, sz, &nums);
    vec![]
  }
}