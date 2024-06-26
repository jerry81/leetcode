/*

2148. Count Elements With Strictly Smaller and Greater Elements
Easy
Topics
Companies
Hint
Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.



Example 1:

Input: nums = [11,7,2,15]
Output: 2
Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
Example 2:

Input: nums = [-3,3,3,90]
Output: 2
Explanation: The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.


Constraints:

1 <= nums.length <= 100
-105 <= nums[i] <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
56.7K
Submissions
95.5K
Acceptance Rate
59.4%

*/

impl Solution {
  pub fn count_elements(nums: Vec<i32>) -> i32 {
    // total
    let tot = nums.clone().len();
    // sort
    let mut sorted = nums.clone();
    sorted.sort();
    let mut bottomCount = 0;
    let mut topCount = 0;

    let bot = sorted[0];
    let top = sorted[tot-1];

    for i in sorted {
      if i == bot { bottomCount+=1; }
      if i == top { topCount+=1; }
    }
    if bottomCount == tot { return 0 }
    tot as i32 - bottomCount as i32 - topCount as i32
  }
}