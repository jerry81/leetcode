/*

1309. Decrypt String from Alphabet to Integer Mapping
Easy
Topics
Companies
Hint
You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.



Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"


Constraints:

1 <= s.length <= 1000
s consists of digits and the '#' letter.
s will be a valid string such that mapping is always possible.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
118.6K
Submissions
149K
Acceptance Rate
79.6%

*/

impl Solution {
  pub fn freq_alphabets(s: String) -> String {
    let char_vector: Vec<char> = s.chars().collect();
    let l = char_vector.len();
    let mut res_vector: Vec<char> = Vec::new();
    let mut idx = 0;
    while idx < l {
      let look_ahead = idx+2;
      if look_ahead < l && char_vector[look_ahead] == '#' {
        let concat = char_vector[idx] + &char_vector[idx+1];
        let digit_i32 = concat.parse::<i32>().unwrap() + 96;
        res.push(std::char::from_u32(digit_i32 as u32).unwrap())
        idx+=3;
      } else {
        let dig = char_vector[idx].to_digit(10).unwrap_or(0) as i32 + 96;
        res.push(std::char::from_u32(dig as u32).unwrap())
        idx+=1;
      }
    }
    res.into_iter().collect()
  }
}