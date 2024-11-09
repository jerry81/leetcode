/*

3133. Minimum Array End
Medium
Topics
Companies
Hint
You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].



Example 1:

Input: n = 3, x = 4

Output: 6

Explanation:

nums can be [4,5,6] and its last element is 6.

Example 2:

Input: n = 2, x = 7

Output: 15

Explanation:

nums can be [7,15] and its last element is 15.



Constraints:

1 <= n, x <= 108
Seen this question in a real interview before?
1/5
Yes
No
Accepted
25.4K
Submissions
56.2K
Acceptance Rate
45.3%

*/



impl Solution {
  pub fn min_end(n: i32, x: i32) -> i64 {
      // bin string of target, x
      let bs:String = format!("{:0>32b}", x);

      0
  }
}

// 0111 - 7
// 1111
//  100
//  101
//. 110
//. 100

// target 100.

// target 10100
// 1x1xx
// 1x1xx
// 1x1xx
// 1x1xx
// 1x1xx
// 1x1xx
// 10100
// 10101
// 10110
// 10111
// 11100
// 11101 16+8+4+1 = 29!