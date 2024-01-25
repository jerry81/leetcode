/*

1394. Find Lucky Integer in an Array
Easy
Topics
Companies
Hint
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.



Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.


Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500
Seen this question in a real interview before?
1/4
Yes
No
Accepted
113.8K
Submissions
171.6K
Acceptance Rate
66.3%

*/

use std::collections::HashMap;

impl Solution {
  pub fn find_lucky(arr: Vec<i32>) -> i32 {
    let mut freq: HashMap<i32,i32> = HashMap::new();
    for i in arr.clone() {
      *freq.entry(i).or_insert(0) += 1;
    }
    let mut res = -1;
    for i in arr.clone() {
      if freq[&i] == i { res = res.max(i) }
    }
    res
  }
}