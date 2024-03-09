/*
2540. Minimum Common Value
Easy
Topics
Companies
Hint
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.



Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.


Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
70K
Submissions
133.9K
Acceptance Rate
52.3%
*/

impl Solution {
  pub fn get_common(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
    let mut ptr1 = 0;
    let mut ptr2 = 0;
    let l1 = nums1.len();
    let l2 = nums2.len();
    while (ptr1 < l1 && ptr2 < l2) {
      let n1 = nums1[ptr1];
      let n2 = nums2[ptr2];
      if n1 == n2 { return n1 }
      if n1 < n2 {
        ptr1+=1;
        continue;
      }
      ptr2+=1;
      continue;
    }
    -1
  }
}