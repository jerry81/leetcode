/*

1624. Largest Substring Between Two Equal Characters
Easy
652
38
Companies
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.


Constraints:

1 <= s.length <= 300
s contains only lowercase English letters.
Accepted
50.4K
Submissions
84.4K
Acceptance Rate
59.7%

*/

use std::collections::HashMap;


impl Solution {

    pub fn max_length_between_equal_characters(s: String) -> i32 {
      // brute
      let mut hm:HashMap<char,Vec<i32>> = HashMap::new();
      for (i, ch) in s.chars().enumerate() {
        let entry = hm.entry(ch).or_insert_with(|| vec![i as i32, 0]);
        entry[1] = i as i32;
      }
      let mut res = -1;
      for (key,value) in &hm {
        let spread = value[1] - value[0];
        res = max(spread,res);
      }
      res
    }
}