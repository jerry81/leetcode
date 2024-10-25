/*

3314. Construct the Minimum Bitwise Array I
Easy
Topics
Companies
Hint
You are given an array nums consisting of n
prime
 integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.



Example 1:

Input: nums = [2,3,5,7]

Output: [-1,1,4,3]

Explanation:

For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.
Example 2:

Input: nums = [11,13,31]

Output: [9,12,15]

Explanation:

For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is 9, because 9 OR (9 + 1) = 11.
For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is 12, because 12 OR (12 + 1) = 13.
For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is 15, because 15 OR (15 + 1) = 31.


Constraints:

1 <= nums.length <= 100
2 <= nums[i] <= 1000
nums[i] is a prime number.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
23.3K
Submissions
31.4K
Acceptance Rate
74.3%

*/

impl Solution {
  pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
    // brute force
    let mut res: Vec<i32> = vec![];
    for n in nums {
      // try all until sum goes over
      let mut found = false;
      for i in 0..n {
        let mut trial = i as i32 | (i+1) as i32;
        if (trial == n) {
          res.push(i);
          found = true;
          break
        }
      }
      if !found {
        res.push(-1);
      }

    }
    res
  }
}