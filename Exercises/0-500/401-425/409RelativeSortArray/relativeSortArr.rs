/*

1122. Relative Sort Array
Easy
2.4K
140
Companies
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.



Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]


Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
Accepted
170.4K
Submissions
248.1K
Acceptance Rate
68.7%

*/

use std::collections::HashSet;
use std::collections::HashMap;

impl Solution {
  pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
    let mut lookup: HashSet<i32> = arr2.iter().cloned().collect();
    let mut freq = HashMap::new();

    for n in &arr1 {
      *freq.entry(*n).or_insert(0) += 1;
    }
    let mut ret: Vec<i32> = Vec::new();
    let mut arr1 = arr1;
    arr1.sort();
    for &n in &arr2 {
      if let Some(&cnt) = freq.get(&n) {
        ret.extend(std::iter::repeat(n).take(cnt as usize));
      }
    }
    for &n in &arr1 {
      if !lookup.contains(&n) {
        ret.push(n);
      }
    }
    ret
  }
}