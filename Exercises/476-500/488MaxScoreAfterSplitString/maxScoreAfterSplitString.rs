impl Solution {
  pub fn max_score(s: String) -> i32 {
    // prefix sums
    let mut zeroes_ps = Vec<i32>::new();
    let mut ones_ps = Vec<i32>::new();
    let mut zc = 0;
    let mut oc = 0;
    for c in s.chars() {
      if c == '0' {
        zc+=1;
      } else {
        oc+=1;
      }
      zeroes_ps.push(zc);
      ones_ps.push(oc);
    }
  }
}