/*


1984. Minimum Difference Between Highest and Lowest of K Scores
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.

Return the minimum possible difference.



Example 1:

Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.
Example 2:

Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.


Constraints:

1 <= k <= nums.length <= 1000
0 <= nums[i] <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
71.8K
Submissions
127K
Acceptance Rate
56.5%

*/

impl Solution {
  pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
    // sort to turn into contiguous problem.  brute force min and max on each subarray
    if k == 1 { return 0 }

    let mut sorted = nums.clone();
    sorted.sort();
    let mut res = i32::MAX;
    let mx_start = nums.len() - k as usize;
    for i in 0..=mx_start {
      let sub:Vec<i32> = sorted[i..i+k as usize].to_vec();
      let dif = sub.last().unwrap() - sub.first().unwrap();
      res = res.min(dif);
    }
    res
  }
}