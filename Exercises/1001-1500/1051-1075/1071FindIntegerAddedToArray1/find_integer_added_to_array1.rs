/*

3131. Find the Integer Added to Array I
Easy
Topics
Companies
Hint
You are given two arrays of equal length, nums1 and nums2.

Each element in nums1 has been increased (or decreased in the case of negative) by an integer, represented by the variable x.

As a result, nums1 becomes equal to nums2. Two arrays are considered equal when they contain the same integers with the same frequencies.

Return the integer x.



Example 1:

Input: nums1 = [2,6,4], nums2 = [9,7,5]

Output: 3

Explanation:

The integer added to each element of nums1 is 3.

Example 2:

Input: nums1 = [10], nums2 = [5]

Output: -5

Explanation:

The integer added to each element of nums1 is -5.

Example 3:

Input: nums1 = [1,1,1,1], nums2 = [1,1,1,1]

Output: 0

Explanation:

The integer added to each element of nums1 is 0.



Constraints:

1 <= nums1.length == nums2.length <= 100
0 <= nums1[i], nums2[i] <= 1000
The test cases are generated in a way that there is an integer x such that nums1 can become equal to nums2 by adding x to each element of nums1.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
58K
Submissions
70.5K
Acceptance Rate
82.3%

*/

impl Solution {
  pub fn added_integer(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
    let mut s1 = nums1.clone();
    s1.sort();
    let mut s2 = nums2.clone();
    s2.sort();
    let s3: Vec<i32> = s1.iter().zip(s2.iter()).map(|i1,i2| {
      i1-i2
    })
    println!("{:?}", s3);
    0
  }
}