impl Solution {
  pub fn apply_operations(nums: Vec<i32>) -> Vec<i32> {
      let mut clone = nums.clone();
      let sz = nums.len();

      for (i, j) in (0..sz-1).zip(1..sz) {
          if clone[i] == clone[j] {
              clone[i] *= 2;
              clone[j] = 0;
          }
      }

      let (mut nonz, zeroes): (Vec<_>, Vec<_>) = clone.into_iter().partition(|&x| x != 0); // .clone() not needed?
      // partition - first -> true case, second -> false case

      nonz.extend(zeroes);

      nonz
  }
}