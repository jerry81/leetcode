/*

1200. Minimum Absolute Difference
Easy
Topics
Companies
Hint
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr


Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]


Constraints:

2 <= arr.length <= 105
-106 <= arr[i] <= 106
Seen this question in a real interview before?
1/4
Yes
No
Accepted
179.2K
Submissions
258.1K
Acceptance Rate
69.4%

*/

impl Solution {
  pub fn minimum_abs_difference(arr: Vec<i32>) -> Vec<Vec<i32>> {
    let mut mn = 100000;
    for i in 0..arr.len()-1 {
      for j in i+1..arr.len() {
        let absdiff = (arr[j]-arr[i]).abs();
        mn = mn.min(absdiff);
      }
    }
    let mut res=Vec::new();
    let mut arr2 = arr;
    arr2.sort();
    for i in 0..arr2.len()-1 {
      for j in i+1..arr2.len() {
        let absdiff = (arr2[j]-arr2[i]).abs();
        if absdiff == mn {
          res.push(vec![arr2[i], arr2[j]]);
        }
      }
    }
    return res;
  }
}