/*

3095. Shortest Subarray With OR at Least K I
Easy
Topics
Companies
Hint
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty
subarray
 of nums, or return -1 if no special subarray exists.



Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.



Constraints:

1 <= nums.length <= 50
0 <= nums[i] <= 50
0 <= k < 64

Seen this question in a real interview before?
1/5
Yes
No
Accepted
28.4K
Submissions
68.7K
Acceptance Rate
41.3%

*/

impl Solution {
  pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
    let l = nums.len();
    let mut res = i32::MAX;
    let mut found = false;
    for i in 0..l {
      for j in i..l {
        let subarr = &nums[i..=j];
        let accum = subarr.iter().fold(0, |res, &item| (res | item) );
        if accum >= k {
            found = true;
            res = res.min(((j-i)+1) as i32);
        }
      }
    }
    if !found { -1 } else { res }
  }
}