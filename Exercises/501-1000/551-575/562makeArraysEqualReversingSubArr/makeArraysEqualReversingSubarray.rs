/*

1460. Make Two Arrays Equal by Reversing Subarrays
Easy
Topics
Companies
Hint
You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.



Example 1:

Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
Example 2:

Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
Example 3:

Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.


Constraints:

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000
Seen this question in a real interview before?
1/4
Yes
No
Accepted
120.7K
Submissions
167.8K
Acceptance Rate
71.9%

*/


use std::collections::HashMap;

impl Solution {

  pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
    let mut freq1:HashMap<i32,i32> = HashMap::new();
    let mut freq2:HashMap<i32,i32> = HashMap::new();
    for i in target {
      *freq1.entry(i).or_insert(0) += 1;
    }
    for i in arr {
      *freq2.entry(i).or_insert(0) += 1;
    }
    for (k,v) in &freq1 {
      match freq2.get(k) { // get into this habit!
        Some(v2) => {
          if v2 != v { return false; }
        },
        None => { return false; }
    }
    }
    true
  }
}