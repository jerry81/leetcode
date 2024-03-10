/*

349. Intersection of Two Arrays
Solved
Easy
Topics
Companies
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
Seen this question in a real interview before?
1/4
Yes
No
Accepted
1M
Submissions
1.4M
Acceptance Rate
72.7%

*/
use std::collections::HashSet;
impl Solution {
  pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut hm1:HashSet<i32> = HashSet::new();
    let mut hm2:HashSet<i32> = HashSet::new();
    for i in nums1 { hm1.insert(i); }
    for i in nums2 { hm2.insert(i); }
    let mut res = Vec::new();
    for i in hm1 { if hm2.contains(&i) { res.push(i); }}
    res
  }
}