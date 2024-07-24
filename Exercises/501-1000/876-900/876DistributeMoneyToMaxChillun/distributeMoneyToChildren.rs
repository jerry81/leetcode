impl Solution {
  pub fn dist_money(money: i32, children: i32) -> i32 {
      // handle each case
      // possible children_with_8
      if children > money { return 0 }

      let mut k = money/8;

      loop { // yes, rust has this
        if k < 0 { return k }
        let remaining_money = money - (k*8);
        let remaining_children = children-k;
        if remaining_children == 1 && remaining_money == 4 {
          k-=1;
          continue
        }
        if remaining_money >= remaining_children { return k }
        k-=1;
      }
      -1
  }
}