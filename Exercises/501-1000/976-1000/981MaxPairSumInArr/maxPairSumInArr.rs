/*


2815. Max Pair Sum in an Array
Easy
Topics
Companies
Hint
You are given an integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the largest digit in both numbers is equal.

For example, 2373 is made up of three distinct digits: 2, 3, and 7, where 7 is the largest among them.

Return the maximum sum or -1 if no such pair exists.



Example 1:

Input: nums = [112,131,411]

Output: -1

Explanation:

Each numbers largest digit in order is [2,3,4].

Example 2:

Input: nums = [2536,1613,3366,162]

Output: 5902

Explanation:

All the numbers have 6 as their largest digit, so the answer is 2536 + 3366 = 5902.

Example 3:

Input: nums = [51,71,17,24,42]

Output: 88

Explanation:

Each number's largest digit in order is [5,7,7,4,4].

So we have only two possible pairs, 71 + 17 = 88 and 24 + 42 = 66.



Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
46.6K
Submissions
79.9K
Acceptance Rate
58.4%

*/

impl Solution {
  // convert int to digit string
  fn get_max_dig(i: i32) -> i32 {
    *i.to_string().chars().map(|c| {
      (c as u8 - '0' as u8) as i32
    }).collect::<Vec<i32>>().iter().max().unwrap()
  }
  pub fn max_sum(nums: Vec<i32>) -> i32 {
    let mut groups: Vec<Vec<i32>> = vec![vec![];10]; // val; size
    for n in nums {
      groups[Solution::get_max_dig(n) as usize].push(n);
    }
    let mut res = 0;
    for g in groups {
      for i in 0..g.len()-1 {
        let first = g[i];
        for j in i+1..g.len() {
          let second = g[j];
          res = res.max(first+second);
        }
      }
    }
    res
  }
}