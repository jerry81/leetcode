/*
3318. Find X-Sum of All K-Long Subarrays I
Easy
Topics
Companies
Hint
You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

Count the occurrences of all elements in the array.
Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
Calculate the sum of the resulting array.
Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the
subarray
 nums[i..i + k - 1].



Example 1:

Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

Output: [6,10,12]

Explanation:

For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
Example 2:

Input: nums = [3,8,7,8,7,5], k = 2, x = 2

Output: [11,15,15,15,12]

Explanation:

Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].



Constraints:

1 <= n == nums.length <= 50
1 <= nums[i] <= 50
1 <= x <= k <= nums.length
Seen this question in a real interview before?
1/5
Yes
No
Accepted
23.7K
Submissions
37.9K
Acceptance Rate
62.7%
*/
use std::collections::HashMap;
impl Solution {
  pub fn find_x_sum(nums: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
    let l = nums.len();
    let mut res : Vec<i32> = vec![];
    for start in 0..=(l-k as usize) {
      let subarr = &nums[start..start+k as usize];
      let mut freq: HashMap<i32,i32> = HashMap::new();
      for i in subarr {
        *freq.entry(*i).or_insert(0) += 1;
      }
      let mut sortable_vec:Vec<(i32,i32)> = freq.iter().map(|(&a,&b)| {
        (b,a)
      }).collect();
      sortable_vec.sort();
      sortable_vec.reverse();
      let mut sm = 0;
      for i in 0..k as usize {
        if i >= sortable_vec.len() { break; }
        sm += sortable_vec[i].1;
      }
      res.push(sm);
    }
    res
  }
}