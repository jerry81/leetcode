/*

3146. Permutation Difference between Two Strings
Easy
Topics
Companies
Hint
You are given two strings s and t such that every character occurs at most once in s and t is a permutation of s.

The permutation difference between s and t is defined as the sum of the absolute difference between the index of the occurrence of each character in s and the index of the occurrence of the same character in t.

Return the permutation difference between s and t.



Example 1:

Input: s = "abc", t = "bac"

Output: 2

Explanation:

For s = "abc" and t = "bac", the permutation difference of s and t is equal to the sum of:

The absolute difference between the index of the occurrence of "a" in s and the index of the occurrence of "a" in t.
The absolute difference between the index of the occurrence of "b" in s and the index of the occurrence of "b" in t.
The absolute difference between the index of the occurrence of "c" in s and the index of the occurrence of "c" in t.
That is, the permutation difference between s and t is equal to |0 - 1| + |1 - 0| + |2 - 2| = 2.

Example 2:

Input: s = "abcde", t = "edbac"

Output: 12

Explanation: The permutation difference between s and t is equal to |0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12.



Constraints:

1 <= s.length <= 26
Each character occurs at most once in s.
t is a permutation of s.
s consists only of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
75.1K
Submissions
84.2K
Acceptance Rate
89.2%

*/

use std::collections::HashMap;

impl Solution {
  pub fn find_permutation_difference(s: String, t: String) -> i32 {
    // make maps
    let mut hm_a: HashMap<char, usize> = HashMap::new();
    let mut hm_b: HashMap<char, usize> = HashMap::new();
    for (c,i) in s.chars().enumerate() {
      *hm_a.entry(c).or_insert(i) = i;
    }
    for c in t.chars() {
      *hm_b.entry(c).or_insert(i) = i
    }
    0
  }
}