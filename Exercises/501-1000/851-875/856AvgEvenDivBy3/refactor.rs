impl Solution {
  pub fn average_value(nums: Vec<i32>) -> i32 {
      let (sum, count) = nums.iter() // iter over for
          .filter(|&&x| x % 2 == 0 && x % 3 == 0) // filter yep, note the &&
          .fold((0, 0), |(sum, count), &x| (sum + x, count + 1)); // TIL: fold!

      if count == 0 {
          0
      }

      (sum as f64 / count as f64) as i32
  }
}