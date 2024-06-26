/*

2357. Make Array Zero by Subtracting Equal Amounts
Easy
Topics
Companies
Hint
You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.



Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
Example 2:

Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
109.8K
Submissions
151.7K
Acceptance Rate
72.4%

*/

impl Solution {
  pub fn minimum_operations(nums: Vec<i32>) -> i32 {
    let mut sorted = nums.clone();
    sorted.sort();
    let mut nz = true;
    let mut res = 0;
    let mut filtered = sorted.to_iter().filter(|&x| x > 0).collect();
    while nz {
      nz = true;
      let mut nxt:Vec<i32> = vec![];
      if filtered.empty() { return res }
      let mn = filtered.first().unwrap();
      for i in filtered {
        if i>mn {
          nxt.push(i-mn);
          nz = false;
        }
      }
      filtered= nxt;
    }
    res
  }
}