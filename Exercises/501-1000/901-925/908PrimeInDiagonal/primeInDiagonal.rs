/*

2614. Prime In Diagonal
Easy
Topics
Companies
Hint
You are given a 0-indexed two-dimensional integer array nums.

Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of the diagonals, return 0.

Note that:

An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
An integer val is on one of the diagonals of nums if there exists an integer i for which nums[i][i] = val or an i for which nums[i][nums.length - i - 1] = val.


In the above diagram, one diagonal is [1,5,9] and another diagonal is [3,5,7].



Example 1:

Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
Output: 11
Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers present on at least one of the diagonals. Since 11 is the largest prime, we return 11.
Example 2:

Input: nums = [[1,2,3],[5,17,7],[9,11,10]]
Output: 17
Explanation: The numbers 1, 3, 9, 10, and 17 are all present on at least one of the diagonals. 17 is the largest prime, so we return 17.


Constraints:

1 <= nums.length <= 300
nums.length == numsi.length
1 <= nums[i][j] <= 4*106
Seen this question in a real interview before?
1/5
Yes
No
Accepted
44.1K
Submissions
129.7K
Acceptance Rate
34.0%

*/

impl Solution {
  is_prime(num: i32) -> bool {
    for i in 2..num.sqrt() {
      if num % (i as i32) == 0 { return true }
    }
    false
  }
  pub fn diagonal_prime(nums: Vec<Vec<i32>>) -> i32 {
    let mut sz = nums.len();
    let mut candidates = vec![];
    for i in 0..sz {
      let diag1 = nums[i][i];
      let diag2 = nums[sz-i-1][i];
      if Solution::is_prime(diag1) {
        candidates.push(diag1);
      }

      // 2,0 1,1 0,2
      if Solution::is_prime(diag2) {
        candidates.push(diag2);
      }
    }
    if candidates.empty() { return 0 }
    candidates.iter().max()
  }
}