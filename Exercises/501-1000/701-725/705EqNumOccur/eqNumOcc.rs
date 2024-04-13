/*


1941. Check if All Characters Have Equal Number of Occurrences
Easy
Topics
Companies
Hint
Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).



Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
91.4K
Submissions
118.3K
Acceptance Rate
77.3%

*/

use std::collections::HashMap;

impl Solution {
  pub fn are_occurrences_equal(s: String) -> bool {
    let mut hm:HashMap<char,i32> = HashMap::new();
    for c in s.chars() {
      *hm.entry(c).or_insert(0) +=1;
    }
    let mut num = -1;
    for (_,v) in hm {
      if num < 0 { num = v }
      if num != v { return false; }
    }
    true
  }
}