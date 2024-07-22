impl Solution {
  pub fn min_max_difference(num: i32) -> i32 {
      let as_str = num.to_string();
      let most_sig_mx = as_str.chars().find(|&c| c != '9').unwrap_or('9'); // o i see.  find replaces the loop - find takes function
      let most_sig_mn = as_str.chars().find(|&c| c != '0').unwrap_or('0'); // which is unlike other languages which finds index

      let mx_str: String = as_str.chars().map(|c| if c == most_sig_mx { '9' } else { c }).collect();
      let mn_str: String = as_str.chars().map(|c| if c == most_sig_mn { '0' } else { c }).collect();

      mx_str.parse::<i32>().unwrap() - mn_str.parse::<i32>().unwrap()
  }
}