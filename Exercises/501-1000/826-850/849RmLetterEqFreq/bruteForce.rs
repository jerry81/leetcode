use std::collections::HashMap;


impl Solution {
  pub fn equal_frequency(word: String) -> bool {
    for i in 0..word.len() {
        let mut chars: Vec<char> = word.chars().collect();
        chars.remove(i);
        if (Solution::works(chars.into_iter().collect())) { return true }
    }
    false
  }

  fn works(word: String) -> bool {
    let mut freq: HashMap<char, i32> = HashMap::new();
    let mut fof: HashMap<i32, i32> = HashMap::new();
    for c in word.chars() {
      *freq.entry(c).or_insert(0) += 1;
    }

    // Count frequency of frequencies
    for (_, f) in &freq {
      *fof.entry(*f).or_insert(0) += 1;
    }
    fof.len() == 1
  }
}