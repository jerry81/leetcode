/*
2185. Counting Words With a Given Prefix
Easy
Topics
Companies
Hint
You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.



Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.


Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
92.9K
Submissions
119.1K
Acceptance Rate
78.0%
*/

impl Solution {
  pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
    let mut res  = 0;
    for w in words {
      if w.starts_with(&pref) { res+=1; }
    }
    res
  }
}