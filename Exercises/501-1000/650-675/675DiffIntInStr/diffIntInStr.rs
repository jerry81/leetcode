/*
1805. Number of Different Integers in a String
Easy
Topics
Companies
Hint
You are given a string word that consists of digits and lowercase English letters.

You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".

Return the number of different integers after performing the replacement operations on word.

Two integers are considered different if their decimal representations without any leading zeros are different.



Example 1:

Input: word = "a123bc34d8ef34"
Output: 3
Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
Example 2:

Input: word = "leet1234code234"
Output: 2
Example 3:

Input: word = "a1b01c001"
Output: 1
Explanation: The three integers "1", "01", and "001" all represent the same integer because
the leading zeros are ignored when comparing their decimal values.


Constraints:

1 <= word.length <= 1000
word consists of digits and lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
46K
Submissions
122.1K
Acceptance Rate
37.7%
*/

use std::collections::HashSet;

impl Solution {
  pub fn num_different_integers(word: String) -> i32 {
    // string manipulation
    // split
    // set
    let mut hs: HashSet<String> = HashSet::new();
    let mut cur: String = String::new();

    for c in word.chars() {
      if c.is_digit(10) {
        cur.push(c);
      } else {
        if !cur.is_empty() {
          hs.insert(cur);
        }
        cur = String::new();
      }
    }
    if !cur.is_empty() {
        hs.insert(cur);
    }
    let mut final_hs: HashSet<String> = HashSet::new();
    // TIL: new method i32::from_str_radix
    for item in hs {
      let mut to_add = String::new();
      let mut leading = true;
      for c in item.chars() {
        if leading && c == '0' {
          continue;
        } else {
          leading = false;
          to_add.push(c);
        }
      }
      if to_add.is_empty() {
        to_add.push(item.chars().last().unwrap())
      }
      final_hs.insert(to_add);
    }
    final_hs.len() as i32
  }
}