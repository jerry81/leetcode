impl Solution {
  pub fn dist_money(money: i32, children: i32) -> i32 {
      // recursive brute force?
      if children > money { return -1; }

      if money/8 == children { return money/8 }
      0
  }
}