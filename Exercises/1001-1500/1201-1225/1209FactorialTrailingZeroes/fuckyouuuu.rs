
impl Solution {
  pub fn trailing_zeroes(n: i32) -> i32 {
    let mut count = 0;
    let mut i = 5;
    // Count factors of 5
    while n >= i {
      count += n / i;
      i *= 5;
    }
    count
  }
}