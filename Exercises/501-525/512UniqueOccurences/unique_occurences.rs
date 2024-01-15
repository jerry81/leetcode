/*

1207. Unique Number of Occurrences
Easy
Topics
Companies
Hint
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.



Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true


Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
Seen this question in a real interview before?
1/4
Yes
No
Accepted
405.7K
Submissions
543K
Acceptance Rate
74.7%

*/

use std::collections::HashMap;

impl Solution {
  let mut freq:HashMap<i32,i32> = HashMap::new();
  let mut rev_freq:HashMap<i32,i32> = HashMap::new();
  pub fn unique_occurrences(arr: Vec<i32>) -> bool {
    for i in arr {
      *freq.entry(i).or_insert(0) += 1;
    }
    for (key, value) in freq.iter() {
      *rev_freq.entry(*value).or_insert(0)+=1;
    }
    for (key,value) in freq.iter() {
      if rev_freq[*value] != 1 {
        false
      }
    }
    true
  }
}