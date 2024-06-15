impl Solution {
  pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
    let mut left = 0;
    let mut right = k;
    let mut wcount = 0;
    for i in left..right {
      if blocks.chars().ith(i) == 'W' {
        wcount+=1;
      }
    }
    let sz = blocks.len();
    let mut res = wcount;

    while right < sz {
      if blocks.chars().ith(left) == 'W' {
        wcount-=1;
      }
      if blocks.chars().ith(right) == 'W' {
        wcount+=1;
      }
      res = res.min(wcount);
      left+=1;
      right+=1;
    }
    res
  }
}