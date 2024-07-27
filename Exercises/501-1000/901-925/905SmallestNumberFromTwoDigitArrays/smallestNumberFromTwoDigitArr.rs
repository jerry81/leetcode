/*

2605. Form Smallest Number From Two Digit Arrays
Easy
Topics
Companies
Hint
Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.


Example 1:

Input: nums1 = [4,1,3], nums2 = [5,7]
Output: 15
Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
Example 2:

Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
Output: 3
Explanation: The number 3 contains the digit 3 which exists in both arrays.


Constraints:

1 <= nums1.length, nums2.length <= 9
1 <= nums1[i], nums2[i] <= 9
All digits in each array are unique.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
37.3K
Submissions
69K
Acceptance Rate
54.0%

*/

impl Solution {
    pub fn min_number(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
      for i in 1..=9 {
        let as_i = i as i32;
        if nums1.contains(&as_i) && nums2.contains(&as_i) {
          return as_i
        }
      }
      let mut sorted1: Vec<i32> = nums1.clone();
      let mut sorted2: Vec<i32> = nums2.clone();
      nums1.sort();
      nums2.sort();

      if sorted1[0] < sorted2 {
        sorted1[0]*10 + sorted2[0]
      } else {
        sorted2[0]*10 + sorted1[0]
      }
    }
}