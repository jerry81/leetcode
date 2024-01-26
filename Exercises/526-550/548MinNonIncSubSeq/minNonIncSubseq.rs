/*

1403. Minimum Subsequence in Non-Increasing Order
Easy
Topics
Companies
Hint
Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence.

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.



Example 1:

Input: nums = [4,3,10,9,8]
Output: [10,9]
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included. However, the subsequence [10,9] has the maximum total sum of its elements.
Example 2:

Input: nums = [4,4,7,6,7]
Output: [7,7,6]
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to be returned in non-decreasing order.


Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
69.4K
Submissions
95.7K
Acceptance Rate
72.6%

*/

impl Solution {

  pub fn min_subsequence(nums: Vec<i32>) -> Vec<i32> {
    let sm:i32 = nums.iter().sum();
    let mn_sum = sm/2;
    let sz = nums.len();
    let mut res: Vec<Vec<i32>> = vec![];

    subseq(vec![], 0, nums, 0, mn_sum, sz, &mut res);
    res.sort_by(|a, b| {
        let size_comparison = a.len().cmp(&b.len());
        if size_comparison == std::cmp::Ordering::Equal {
            b.iter().sum::<i32>().cmp(&a.iter().sum::<i32>())
        } else {
            size_comparison
        }
    });
    let mut first_item: Vec<i32> = res.into_iter().next().unwrap();
    first_item.sort();
    first_item
  }
}

fn subseq(cur: Vec<i32>, idx: usize, nums:Vec<i32>, cur_sum: i32, mn_sum: i32, sz: usize, accum: &mut Vec<Vec<i32>>) {
  let nc = nums.clone();
  let cc = cur.clone();
  if idx >= sz {

    if cur_sum > mn_sum {
        accum.push(cur);
    }
    return;
  }
  // take
  let mut nxt = cur.clone();
  nxt.push(nums[idx]);
  let nxtsum = cur_sum+nums[idx];
  subseq(nxt, idx+1, nums, nxtsum, mn_sum, sz,accum);
  // leave
  subseq(cur, idx+1, nc, cur_sum, mn_sum, sz, accum);
}