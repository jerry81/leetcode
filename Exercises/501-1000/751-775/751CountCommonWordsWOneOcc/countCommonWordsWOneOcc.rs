/*

2085. Count Common Words With One Occurrence
Easy
Topics
Companies
Hint
Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.



Example 1:

Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
Example 2:

Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.
Example 3:

Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".


Constraints:

1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] and words2[j] consists only of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
64.5K
Submissions
92K
Acceptance Rate
70.2%

*/

use std::collections::HashMap;

impl Solution {
  pub fn count_words(words1: Vec<String>, words2: Vec<String>) -> i32 {
    // more counting, freq
    let mut freq1: HashMap<String, i32> = HashMap::new();
    let mut freq2: HashMap<String, i32> = HashMap::new();
    for w in words1 {
      *freq1.entry(w).or_insert(0) +=1;
    }
    for w in words2 {
      *freq2.entry(w).or_insert(0) +=1;
    }
    let mut res = 0;
    for (k,v) in freq1.clone() {
      match freq2.get(&k) {
        Some(v2) => {
          if v == 1 && *v2 == 1 { res+=1; }
        }
        None => {
          continue
        }
      }
    }
    res
  }
}