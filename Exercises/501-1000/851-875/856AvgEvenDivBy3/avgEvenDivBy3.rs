/*


Code
Testcase
Test Result
Test Result
2455. Average Value of Even Numbers That Are Divisible by Three
Easy
Topics
Companies
Hint
Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.

Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.



Example 1:

Input: nums = [1,3,6,10,12,15]
Output: 9
Explanation: 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.
Example 2:

Input: nums = [1,2,4,7,10]
Output: 0
Explanation: There is no single number that satisfies the requirement, so return 0.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
56.8K
Submissions
94.2K
Acceptance Rate
60.4%

*/

impl Solution {
  pub fn average_value(nums: Vec<i32>) -> i32 {
    let mut sm = 0;
    let mut cnt = 0;
    for i in nums {
      if i%2 == 0 && i % 3 == 0 {
        sm+=i;
        cnt+=1;
      }
    }
    (sm as f64 / cnt as f64) as i32
  }
}