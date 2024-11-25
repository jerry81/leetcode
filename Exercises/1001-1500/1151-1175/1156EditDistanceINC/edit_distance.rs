/*
72. Edit Distance
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1M
Submissions
1.8M
Acceptance Rate
57.7%
*/

impl Solution {
  pub fn min_distance(word1: String, word2: String) -> i32 {
    let l1 = word1.len();
    let l2 = word2.len();
    let mut dp: Vec<Vec<i32>> = vec![vec![0;l2+1]; l1+1];
    for i in 0..=l1 {
      for j in 0..=l2 {
        if i == 0 {
          dp[i][j] = j as i32;
          continue
        }
        if j == 0 {
          dp[i][j] = i as i32;
          continue
        }
        if word1.chars().nth(i-1).unwrap() == word2.chars().nth(j-1).unwrap() {
          dp[i][j] = dp[i-1][j-1];
        } else {
          // insert
          // replace
          // delete
          dp[i][j] = 1 + dp[i][j-1].min(dp[i-1][j]).min(dp[i-1][j-1]);

        }
      }
    }
    if l1 == 0 { return l2 as i32 }
    if l2 == 0 { return l1 as i32 }
    dp[l1][l2]
  }
}

// insert delete replace
// something with subsequences?

