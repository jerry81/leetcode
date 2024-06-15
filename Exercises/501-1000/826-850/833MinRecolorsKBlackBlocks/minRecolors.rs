impl Solution {
  pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
    let mut left = 0 as usize;
    let mut right = k as usize;
    let mut wcount = 0;
    for i in left..right {
      if blocks.chars().nth(i).unwrap() == 'W' {
        wcount+=1;
      }
    }
    let sz = blocks.len();
    let mut res = wcount;

    while right < sz {
      if blocks.chars().nth(left).unwrap() == 'W' {
        wcount-=1;
      }
      if blocks.chars().nth(right).unwrap() == 'W' {
        wcount+=1;
      }
      res = res.min(wcount);
      left+=1;
      right+=1;
    }
    res
  }
}