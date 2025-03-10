/*
873. Length of Longest Fibonacci Subsequence
Medium
Topics
Companies
A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].



Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].


Constraints:

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
70.1K
Submissions
143.9K
Acceptance Rate
48.7%
*/
use std::collections::HashSet;

impl Solution {
  pub fn len_longest_fib_subseq(arr: Vec<i32>) -> i32 {
    // brute force iterate subsequences
    let mut hs: HashSet<i32> = HashSet::new();
    let mut res = 0;
    for i in &arr {
      hs.insert(*i);
    }
    let n = &arr.len();
    for i in 0..(*n-1) {
      for j in (i+1)..*n {
        let mut a = arr[i];
        let mut b = arr[j];
        let mut cur_res = 2;
        let mut sum = a+b;
        while hs.contains(&sum) {
          cur_res+=1;
          a = b;
          b = sum;
          sum = a+b;
          res = res.max(cur_res);
        }
      }
    }
    res
  }
}