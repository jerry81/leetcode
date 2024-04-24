/*

2016. Maximum Difference Between Increasing Elements
Easy
Topics
Companies
Hint
Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.



Example 1:

Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
Example 2:

Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].
Example 3:

Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.


Constraints:

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
80.3K
Submissions
143.2K
Acceptance Rate
56.1%
Topics
Companies
Hint 1
Could you keep track of the minimum element visited while traversing?
Hint 2
We have a potential candidate for the answer if the prefix min is lesser than nums[i].
Similar Questions
Discussion (8)

*/

impl Solution {
  pub fn maximum_difference(nums: Vec<i32>) -> i32 {
    let mut mn = -1;
    let mut res = -1;
    for i in nums {
      if mn == -1 {
        mn = i;
        continue
      }

      if i < mn {
        // decreasing
        mn = i;
      } else {
        res = res.max(i - mn);
      }
    }
    res
  }
}
// prefix mins
/*
 nums = [7,1,5,4]
 ps - [7,1,1,1]
*/
