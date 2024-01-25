impl Solution {
  pub fn count_largest_group(n: i32) -> i32 {
      let sum_dig = |mut x| { // lambda function!
          let mut sum = 0;
          loop {
              sum += x % 10; // no char conversions!
              x /= 10;
              if x < 10 {
                  break sum + x; // what is this - break and return
              }
          }
      };

      let mut arr_groups = [0; 37]; // 9999 - 36 max sum
      // no vec!
      let mut max_group = 0;

      (1..=n as usize).map(|x| sum_dig(x)).for_each(|x| { // map, for_each, oh my!
          arr_groups[x] += 1;
          max_group = max_group.max(arr_groups[x]);
      });

      arr_groups.iter().filter(|&&x| x == max_group).count() as i32 // lookin so much like js
  }
}