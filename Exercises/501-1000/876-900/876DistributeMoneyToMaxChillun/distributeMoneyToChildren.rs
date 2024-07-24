impl Solution {
  pub fn dist_money(money: i32, children: i32) -> i32 {
      // handle each case
      // possible children_with_8
      if children > money { return -1 }
      let mut possible_children_with_8 = children.min(money/8);

      let remaining_money = money%8;
      while remaining_money < children-possible_children_with_8 {
        possible_children_with_8-=1;
        if possible_children_with_8 < 0 { return 0 }
      }
      if money%8 == 4 && children - possible_children_with_8 == 1 {
        possible_children_with_8 -= 1;
      }
      possible_children_with_8
  }
}