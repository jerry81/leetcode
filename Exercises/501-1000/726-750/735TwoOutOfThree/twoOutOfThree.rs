/*


2032. Two Out of Three
Easy
Topics
Companies
Hint
Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.


Example 1:

Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
Example 2:

Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
Output: [2,3,1]
Explanation: The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
Example 3:

Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
Output: []
Explanation: No value is present in at least two arrays.


Constraints:

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
66.3K
Submissions
88.5K
Acceptance Rate
74.9%

*/

use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
  pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32> {
    // dedup and count
    // TIL: hashset for dedup
    let d1:HashSet<i32> = nums1.into_iter().collect();
    let d2:HashSet<i32> = nums2.into_iter().collect();
    let d3:HashSet<i32> = nums3.into_iter().collect();
    let mut counts: HashMap<i32,i32> = HashMap::new();
    for d in [d1,d2,d3] {
      for i in d {
        *counts.entry(i).or_insert(0)+=1;
      }
    }
    let mut res: Vec<i32> = Vec::new();
    for (k,v) in counts {
      if v > 1 {
        res.push(k);
      }
    }
    res
  }
}