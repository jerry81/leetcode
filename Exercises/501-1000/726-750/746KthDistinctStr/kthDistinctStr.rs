/*

2053. Kth Distinct String in an Array
Easy
Topics
Companies
Hint
A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.



Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned.
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".


Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
61.9K
Submissions
85.2K
Acceptance Rate
72.7%

*/

use std::collections::HashMap;

impl Solution {
  pub fn kth_distinct(arr: Vec<String>, k: i32) -> String {
    let cloned = arr.clone();
    let mut hm: HashMap<String, i32> = HashMap::new();

    for s in arr {
      *hm.entry(s).or_insert(0) += 1;
    }

    let mut filtered: Vec<String> = cloned
      .into_iter()
      .filter(|item| hm[item.as_str()] == 1)
      .collect();
    if let Some(result) = filtered.get((k-1) as usize) {
      return result.clone();
    } else {
      return "".to_string();
    }
  }
}