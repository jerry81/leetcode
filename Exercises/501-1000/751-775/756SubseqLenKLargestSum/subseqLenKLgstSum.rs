/*


2099. Find Subsequence of Length K With the Largest Sum
Easy
Topics
Companies
Hint
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.



Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation:
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7.
Another possible subsequence is [4, 3].


Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length
Seen this question in a real interview before?
1/5
Yes
No
Accepted
48.7K
Submissions
112.1K
Acceptance Rate
43.5%

*/


impl Solution {

  fn r(idx: usize, nums: &Vec<i32>, left: i32, lookup: &Vec<Vec<i32>>, sz: i32) -> i32 {
    if left <= 0 { return 0 }

    if idx >= sz { return 0 }

    if lookup[left][idx] >= 0 { return lookup[left][idx] }
    let nxt = idx+1;
    let res = max(r(nxt, nums, left, lookup, sz), nums[idx] + res(nxt, nums, left-1, lookup, sz));
    lookup[left][idx] = res;
    res
  }

  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut lookup = Vec::with_capacity(&k);
    let sz = nums.len();

    for i in 0..sz {
      let mut vc :Vec<i32> = vec![-1: sz];
      lookup.push(vc);
    }

    r(0,&nums, k, &lookup, sz)
  }
}