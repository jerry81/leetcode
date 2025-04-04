/*
2559. Count Vowel Strings in Ranges
Medium
Topics
Companies
Hint
You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.



Example 1:

Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].


Constraints:

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= li <= ri < words.length
Seen this question in a real interview before?
1/5
Yes
No
Accepted
46.5K
Submissions
79.1K
Acceptance Rate
58.8%
*/

impl Solution {
  const VOWELS: &'static [char] = &['a', 'e', 'i', 'o', 'u'];
  pub fn vowel_strings(words: Vec<String>, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let mut words_matching: Vec<bool> = words.iter().map(|word| {
      Self::VOWELS.contains(&word.chars().next().unwrap()) && Self::VOWELS.contains(&word.chars().last().unwrap())
    }).collect();
    let mut prefix_sums: Vec<i32> = vec![];
    let mut cnt = 0;
    for w in words_matching {
      if w {
        cnt+=1;
      }
      prefix_sums.push(cnt);
    }
    queries.iter().map(|q| {
      let mut prev = if q[0] == 0 { 0 } else { prefix_sums[(q[0]-1) as usize] };
      prefix_sums[q[1] as usize] - prev
    }).collect()
  }
}