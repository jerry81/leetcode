/*
1684. Count the Number of Consistent Strings
Easy
Topics
Companies
Hint
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.



Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.


Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
166.5K
Submissions
200.8K
Acceptance Rate
82.9%
*/

use std::collections::HashSet;

impl Solution {
  pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
    let mut hs:HashSet<char> = HashSet::new();
    for c in allowed.chars() {
      hs.insert(c);
    }
    let mut res = 0;
    for word in words {
      let mut found = true;
      for c in word.chars() {
        if !&hs.contains(&c) {
          found = false;
          break;
        }

      }
      if found { res+=1 }
    }
    res
  }
}