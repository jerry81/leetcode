use std::sync::Mutex;

lazy_static! {
    static ref ALL: Mutex<Vec<Vec<i32>>> = Mutex::new(Vec::new());
}

impl Solution {
  fn r(cur: Vec<i32>, idx: usize, remain: i32, sz: usize, nums: &Vec<i32>, req: usize) {
    if idx >= sz || remain <= 0 {
      if cur.len() != req { return }
      let mut all = ALL.lock().unwrap(); // so it's a threading thing
      all.push(cur.clone());
      drop(all);
      return
    }

    Self::r(cur.clone(), idx+1, remain, sz, nums, req);

    let mut nxt = cur.clone();
    nxt.push(nums[idx]);
    Self::r(nxt, idx+1, remain-1, sz, nums, req);
  }
  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let sz = nums.len();
    Self::r(vec![], 0, k, sz, &nums, k as usize);
    // println!("printing all");

    let mut mx = 0;
    let mut res = vec![];
    let all = ALL.lock().unwrap();
    for v in all.iter() {
      let sm = v.iter().sum();
      if sm > mx {
        res = v.clone();
        mx = sm;
      }
    }
    res
  }
}