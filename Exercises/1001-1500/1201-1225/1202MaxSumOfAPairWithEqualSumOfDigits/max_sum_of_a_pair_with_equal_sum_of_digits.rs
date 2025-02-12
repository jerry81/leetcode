/*
2342. Max Sum of a Pair With Equal Sum of Digits
Medium
Topics
Companies
Hint
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.



Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
71.4K
Submissions
120.7K
Acceptance Rate
59.1%
*/

use std::collections::BTreeSet;
use std::collections::HashMap;
use std::cmp::Reverse; // til

impl Solution {
  fn sum_digits(num: i32) -> i32 {
    let mut sum = 0;
    for c in num.to_string().chars() {
      sum+=((c as u8)-'0' as u8) as i32;
    }
    sum
  }
  pub fn maximum_sum(nums: Vec<i32>) -> i32 {
    let mut hm: HashMap<i32, BTreeSet<Reverse<i32>>> = HashMap::new(); // til
    for n in nums {
      let sm = Solution::sum_digits(n);
      hm.entry(sm).or_insert(BTreeSet::new()).insert(Reverse(n)); // reverse the btreeset
    }
    let mut res = -1;
    for (a,b) in hm {
      if b.len() < 2 { continue }

      let top_two_sum = b.iter().take(2).map(|item|{item.0}).sum();
      res = res.max(top_two_sum);
    }
    res
  }
}