impl Solution {
  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
      let mut sorted: Vec<(i32,usize)> = Vec::new();
      let sz = nums.len();

      for i in 0..sz {
        sorted.push((nums[i],i));
      }

      sorted.sort_by(|a,b| { a.0.cmp(&b.0) });
      let mut pre_res: Vec<(i32,usize)> = Vec::new();
      for i in 0..k {
        pre_res.push(sorted[sz-i-1]);
      }

      let mut res = vec![];
      pre_res.sort_by(|a,b| { a.1.cmp(&b.1) });
      for (v,_) in pre_res {
        res.push(v);
      }
      res
  }
}