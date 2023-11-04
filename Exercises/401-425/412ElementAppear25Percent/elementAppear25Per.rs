/*

1287. Element Appearing More Than 25% In Sorted Array
Easy
908
45
Companies
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.



Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1


Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105
Accepted
86K
Submissions
145.6K
Acceptance Rate
59.1%

*/

use std::collections::HashMap;

impl Solution {
  pub fn find_special_integer(arr: Vec<i32>) -> i32 {
    let thresh = arr.len() as i32 / 4;
    let mut res = 0;
    let mut freq: HashMap<i32,i32> = HashMap::new();
    for i in arr {
      *freq.entry(i).or_insert(0) += 1;
    }
    for (k, v) in &freq {
      if *v > thresh {
        return *k
      }
    }
    0
  }
}