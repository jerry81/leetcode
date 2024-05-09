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
use std::sync::{Mutex};
use lazy_static::lazy_static;

lazy_static! {
  static ref resArr: Mutex<Vec<i32>> = Mutex::new(vec![]);
  static ref ressz: Mutex<i32> = Mutex::new(0);
}
impl Solution {

  fn r(idx: usize, nums: &Vec<i32>, left: i32, cur: Vec<i32>, lookup: &Vec<Vec<i32>>, sz: &usize) -> i32 {
    if left <= 0 { return 0 }

    if idx >= *sz { return 0 }

    if lookup[left as usize][idx] >= 0 { return lookup[left as usize][idx] }
    let nxt = idx+1;

    let mut nxtArr = cur.clone();
    let mut nxtArr2 = cur.clone();
    let mut res = Solution::r(nxt, nums, left, nxtArr, lookup, sz);
    let curV = nums[idx];
    nxtArr2.push(curV);
    res = res.max(curV + Solution::r(nxt, nums, left-1, nxtArr2, lookup, sz));
    let mut ra = resArr.lock().unwrap();
    lookup[left as usize][idx] = res;
    if res > *ressz.lock().unwrap() {
      *ressz.lock().unwrap() = res;
      *ra = cur.clone();
    }
    res
  }

  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut lookup = Vec::with_capacity(k as usize);
    let sz = nums.len();

    for i in 0..sz {
      let mut vc :Vec<i32> = vec![-1; sz]; // note it is a semicolon, not a colon
      lookup.push(vc);
    }

    Solution::r(0,&nums, k, &lookup, &sz);
    resArr.lock().unwrap().clone()
  }
}