/*

53. Maximum Subarray
Medium
Topics
Companies
Given an integer array nums, find the
subarray
 with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
4.4M
Submissions
8.6M
Acceptance Rate
51.4%
*/

impl Solution {
  pub fn max_sub_array(nums: Vec<i32>) -> i32 {
    // brute - try all subarrays
    // two pointer
    // if left is neg then left++
    let mut rp = 0;
    let mut res = i32::MIN;
    let mut cur = 0;
    let n = nums.len();
    for lp in 0..n {
      cur+=nums[rp];
      res = res.max(cur);
      while rp < lp && nums[rp] > 0 {
        rp+=1;
        cur+= nums[rp];
      }
      cur-=nums[lp];
    }
    res
  }
}