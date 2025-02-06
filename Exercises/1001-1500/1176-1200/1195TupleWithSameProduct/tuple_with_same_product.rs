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
    // cache pairs
    let mut hm: HashMap<usize,HashMap<usize,(i32,i32,i32)>> = HashMap::new();
    let sz = nums.len();
    for i in 0..(sz-1) {
      let ni = nums[i];
      hm[&i] = HashMap::new();
      for j in i+1..sz {
        let nj = nums[j];
        hm[&i][&j]=(ni,nj,ni*nj);
      }
    }
    let mut res = 0;
    for (idx1, hm1) in hm {
      for (idx2, (x1,x2,x3)) in hm1 {
        println!("working with idx1 {}, idx2 {}, x1,x2,x3 {},{},{}", idx1, idx2, x1,x2,x3);
      }
    }
    0
  }
}

/*

hm is {1: {2: (3, 4, 12), 3: (3, 6, 18)}, 2: {3: (4, 6, 24)},
0: {3: (2, 6, 12), 2: (2, 4, 8), 1: (2, 3, 6)}}

*/
