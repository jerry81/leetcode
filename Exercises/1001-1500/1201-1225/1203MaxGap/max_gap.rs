/*
164. Maximum Gap
Medium
Topics
Companies
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.



Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
256.1K
Submissions
529.4K
Acceptance Rate
48.4%
*/

impl Solution {
  pub fn maximum_gap(nums: Vec<i32>) -> i32 {
    let mut v: Vec<i32> = vec![0; 1000000001];
    for n in nums {
      v[n as usize]+=1;
    }
    let mut res = 0;
    let mut prev :i32= -1;
    for i in 0..v.len() {
      if v[i] > 0 {
        if prev < 0 {
            prev = i as i32;
        } else {
            res = res.max(i as i32 - prev);
            prev=i as i32;
        }
      }
    }
    res
  }
}