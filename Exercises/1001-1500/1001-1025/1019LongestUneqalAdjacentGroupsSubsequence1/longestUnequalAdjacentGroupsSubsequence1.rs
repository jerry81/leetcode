/*

2900. Longest Unequal Adjacent Groups Subsequence I
Easy
Topics
Companies
Hint
You are given a string array words and a binary array groups both of length n, where words[i] is associated with groups[i].

Your task is to select the longest alternating
subsequence
 from words. A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements in the binary array groups differ. Essentially, you are to choose strings such that adjacent elements have non-matching corresponding bits in the groups array.

Formally, you need to find the longest subsequence of an array of indices [0, 1, ..., n - 1] denoted as [i0, i1, ..., ik-1], such that groups[ij] != groups[ij+1] for each 0 <= j < k - 1 and then find the words corresponding to these indices.

Return the selected subsequence. If there are multiple answers, return any of them.

Note: The elements in words are distinct.



Example 1:

Input: words = ["e","a","b"], groups = [0,0,1]

Output: ["e","b"]

Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2]. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,0,1,1]

Output: ["a","b","c"]

Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.



Constraints:

1 <= n == words.length == groups.length <= 100
1 <= words[i].length <= 10
groups[i] is either 0 or 1.
words consists of distinct strings.
words[i] consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
30K
Submissions
48.3K
Acceptance Rate
62.2%

*/

impl Solution {
  fn r(gr: &Vec<i32>, idx: usize, last_group: i32) -> Vec<i32> {
    // take or leave
    if idx == gr.len() {
      return Vec::new();
    }
    let mut take = Vec::new();
    if gr[idx] != last_group {
      take = Self::r(gr, idx + 1, gr[idx]);
      take.push(idx as i32);
    }
    let leave = Self::r(gr, idx + 1, last_group);
    if take.len() > leave.len() {
      take
    } else {
      leave
    }
  }

  pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
    let mut ans_idx = Vec::new();
    let mut ans_words = Vec::new();
    let mut last_group = -1;
    for idx in 0..words.len() {
      let take = Self::r(&groups, idx, last_group);
      if take.len() > ans_idx.len() {
        ans_idx = take;
        ans_words = take.iter().map(|i| words[*i as usize].clone()).collect();
      }
    }
    ans_words
  }
}