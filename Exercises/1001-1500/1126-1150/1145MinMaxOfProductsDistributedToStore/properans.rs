impl Solution {
  pub fn minimized_maximum(n: i32, quantities: Vec<i32>) -> i32 {
      let (mut left, mut right) = (1, *quantities.iter().max().unwrap());
      while left < right {
          let mid = (left + right) / 2;
          let stores_needed: i32 = quantities.iter().map(|&q| (q + mid - 1) / mid).sum();
          if stores_needed <= n {
              right = mid; // Try for a smaller maximum
          } else {
              left = mid + 1; // Increase the maximum
          }
      }
      left
  }
}