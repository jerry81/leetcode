/*

1365. How Many Numbers Are Smaller Than the Current Number
Easy
Topics
Companies
Hint
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.



Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation:
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1).
For nums[3]=2 there exist one smaller number than it (1).
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]


Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
517.6K
Submissions
597.9K
Acceptance Rate
86.6%

*/

use std::collections::HashMap;

impl Solution {
  pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
      let mut sorted = nums.clone(); // clone, not &
      sorted.sort();
      let mut hm: HashMap<i32,i32> = sorted.iter().enumerate() // enumerate map chain TIL to directly convert the vec to hm
        .fold(HashMap::new(), |mut acc, (idx, &v)| { // similar to es6 reduce
          acc.entry(v).or_insert(idx as i32);
          acc
        });

      let mut res: Vec<i32> = nums.iter().map(|&i| hm[&i])
        .collect();
      res
  }
}