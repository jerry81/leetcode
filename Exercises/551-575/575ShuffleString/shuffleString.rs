/*

1528. Shuffle String
Easy
Topics
Companies
Hint
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.



Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.


Constraints:

s.length == indices.length == n
1 <= n <= 100
s consists of only lowercase English letters.
0 <= indices[i] < n
All values of indices are unique.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
356.7K
Submissions
421.8K
Acceptance Rate
84.6%

*/

use std::collections::HashMap;

impl Solution {
  pub fn restore_string(s: String, indices: Vec<i32>) -> String {
    let mut hm: HashMap<i32,char> = HashMap::new();
    for (i, &idx) in indices.iter().enumerate() {
      println!("i is {} idx is {}", i, &idx);
      hm.insert(idx, s.chars().nth(i).unwrap());
    }
    let sorted_entries: Vec<(i32, char)> = hm.into_iter().collect(); // convert to vec of tuples
    for (key, value) in sorted_entries.into_iter().sorted_by_key(|&(k, _)| k) { // iter has sorted_by_key on it
      sorted_char_map.insert(key, value);
  }

  let ret: String = (0..s.len() as i32).map(|i| sorted_char_map[&i]).collect();
    "".to_string();
  }
}