impl Solution {
  pub fn gray_code(n: i32) -> Vec<i32> {
    let mut res: Vec<i32> = vec![0]; // Start with the base case for n = 0

    for i in 0..n {
      let len = res.len();
      // Reflect the current sequence and prepend 1 to the reflected values
      for j in (0..len).rev() {
        res.push(res[j] | (1 << i)); // Add leading 1 to the reflected values
      }
    }

    res
  }
}