/*

1726. Tuple with Same Product
Medium
Topics
Companies
Hint
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.



Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
All elements in nums are distinct.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
47.3K
Submissions
72.7K
Acceptance Rate
65.1%

*/
use std::collections::HashMap;

impl Solution {
  pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
    // cache products
    let mut product_map: HashMap<i32, Vec<(usize, usize)>> = HashMap::new();
    let sz = nums.len();

    for i in 0..(sz-1) {
      let ni = nums[i];
      for j in i+1..sz {
        let nj = nums[j];
        let product = ni * nj;
        product_map.entry(product).or_insert(Vec::new()).push((i, j)); // Updated this line
      }
    }

    let mut res = 0;
    for pairs in product_map.values() {
      let count = pairs.len();
      if count > 1 {
        res += count * (count - 1) * 4; // Each pair can form 4 permutations
      }
    }

    res as i32
  }
}

/*

hm is {1: {2: (3, 4, 12), 3: (3, 6, 18)}, 2: {3: (4, 6, 24)},
0: {3: (2, 6, 12), 2: (2, 4, 8), 1: (2, 3, 6)}}

*/
