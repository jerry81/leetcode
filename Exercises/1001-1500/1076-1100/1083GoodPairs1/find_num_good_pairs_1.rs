/*

3162. Find the Number of Good Pairs I
Easy
Topics
Companies
Hint
You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.

A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).

Return the total number of good pairs.



Example 1:

Input: nums1 = [1,3,4], nums2 = [1,3,4], k = 1

Output: 5

Explanation:

The 5 good pairs are (0, 0), (1, 0), (1, 1), (2, 0), and (2, 2).
Example 2:

Input: nums1 = [1,2,4,12], nums2 = [2,4], k = 3

Output: 2

Explanation:

The 2 good pairs are (3, 0) and (3, 1).



Constraints:

1 <= n, m <= 50
1 <= nums1[i], nums2[j] <= 50
1 <= k <= 50
Seen this question in a real interview before?
1/5
Yes
No
Accepted
67.6K
Submissions
77.9K
Acceptance Rate
86.8%

*/

impl Solution {
  pub fn number_of_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i32 {
    let n = nums1.len();
    let m = nums2.len();
    let mut res = 0;
    for i in 0..n {
      let first = nums1[i];
      for j in 0..m {
        let second = nums2[j];
        if first % (second*k) == 0 { res+=1 }
      }
    }
    res
  }
}