impl Solution {
  pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    let mut ptr1: usize = 0;
    let mut cur_count = 0;
    let n = nums.len();
    let mut cur_val = -1;
    for ptr2 in 0..n {
      let item = nums[ptr2];
      if item != cur_val {
        cur_count = 1;
        cur_val = item;
      } else {
        cur_count+=1;
      }
      if cur_count <= 2 {
        nums[ptr1] = item;
        ptr1+=1;
      }
    }
    ptr1 as i32
  }
}