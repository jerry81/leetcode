/*

3005. Count Elements With Maximum Frequency
Easy
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.



Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
44.3K
Submissions
60.1K
Acceptance Rate
73.7%

*/

use std::collections::HashMap;

impl Solution {
  pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
    let mut freq:HashMap<i32, i32> = HashMap::new();
    for i in nums {
      *freq.entry(i).or_insert(0)+=1;
    }
    let mut mx = 0;
    for (_,v) in &freq {
      mx = mx.max(*v);
    }
    let mut multiplier = 0;
    for (_k,v) in &freq {
      if *v == mx { multiplier += 1; }
    }
    multiplier*mx
  }
}