impl Solution {
  pub fn odd_string(words: Vec<String>) -> String {
      let mut baseline: Option<Vec<i32>> = None; // use option for cases where you want some null handling
      let mut conflict = false;
      let mut res: String = "".to_string();
      let mut orig: String = "".to_string();

      for word in words {
          let cur = Solution::make_diff_arr(&word);
          if let Some(base) = &baseline { // removes need for init flag
              if base != &cur { // direct compare
                  if conflict {
                      return orig;
                  } else {
                      conflict = true;
                      res = word.clone(); // clone over &...to_string()
                  }
              }
          } else {
              baseline = Some(cur); // setting an optional
              orig = word.clone();
          }
      }
      res
  }

  fn make_diff_arr(word: &str) -> Vec<i32> {
      word.chars()
          .zip(word.chars().skip(1))
          .map(|(first, second)| (second as i32) - (first as i32))
          .collect() // wow zip combines two iterators
          // skip returns iterator skipping one item
          // zip only continues when both iterators still have items
  }
}
