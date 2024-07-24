impl Solution {
  pub fn dist_money(money: i32, children: i32) -> i32 {
      // handle each case
      // possible children_with_8
      if children > money { return -1 }
      let possible_children_wth_8 = children.min(money/8);
      println!("possible {}", possible_children_wth_8);
      if money%8 == 4 && children-possible_children_with_8 == 1 {
        possible_children_with_8 -= 1;
      }
      possible_children_with_8
  }
}