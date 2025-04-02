/*


187. Repeated DNA Sequences
Medium
Topics
Companies
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.



Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]


Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
439.7K
Submissions
864.2K
Acceptance Rate
50.9%

*/

use std::collections::HashSet;

impl Solution {
  pub fn find_repeated_dna_sequences(s: String) -> Vec<String> {
    // brute force with early stops?
    // store
    let mut res: HashSet<String> = HashSet::new();
    let mut hs: HashSet<String> = HashSet::new();
    let n = s.len();
    if n < 10 { return vec![] }
    for i in 0..=(n-10) {
      let substr = s[i..(i+10)].to_string();
      if hs.contains(&substr) { res.insert(substr.clone()); }
      hs.insert(substr);
    }
    let resv: Vec<String> = res.into_iter().collect();
    resv
  }
}