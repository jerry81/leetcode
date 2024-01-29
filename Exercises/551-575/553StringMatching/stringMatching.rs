/*

1408. String Matching in an Array
Easy
Topics
Companies
Hint
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string



Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
82.2K
Submissions
128.9K
Acceptance Rate
63.8%

*/
impl Solution {
  pub fn string_matching(words: Vec<String>) -> Vec<String> {
    let mut cpy = words.clone();
    cpy.sort_by(|a,b| { a.len().cmp(&b.len()) });
    /*
      q.  yo, so why does cmp want a &
    */
    let mut res = Vec::new();
    for i in 0..cpy.len()-1 {
      for j in i..cpy.len() {
        let a = &cpy[i];
        /*
          q.  when wanting to access with index i found we need to use & - why?
          a.  part of the whole borrowing rules.  memory safety
          & indicates borrowing - ref to original data, ownership still with original owner
        */
        let b = &cpy[j];
        if b.contains(&a) {
          res.push(a);
        }
      }
    }
    res
  }
}