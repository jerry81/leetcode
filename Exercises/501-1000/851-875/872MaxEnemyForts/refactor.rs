
impl Solution {
  pub fn capture_forts(forts: Vec<i32>) -> i32 {
    let mut starting_positions: Vec<usize> = Vec::new();
    for i in 0..forts.len() {
      if forts[i] == 1 { starting_positions.push(i); }
    }
    let mut res = 0 ;
    // for each starting position look left and look right
    for sp in starting_positions {
      // go left
      res = res.max(Solution::check(forts.clone(), sp, false));
      res = res.max(Solution::check(forts.clone(), sp, true));
    }
    res
  }

  fn check(forts: Vec<i32>, sp: usize, dec: bool) -> i32 {
    let addend: i32 = if dec { -1 } else { 1 };
    if sp == 0 && dec { return 0 }
    let mut idx = (sp as i32 + addend) as usize;
    let mut curcount = 0;
    let mut found = false;

    while idx < forts.len() && idx >= 0 {
      if forts[idx] == 0 {
        curcount += 1;
      } else if forts[idx] == -1 {
        found = true;
        break;
      } else {
        break;
      }
      idx+=addend as usize;
    }
    if found { curcount } else { 0 }
  }
}