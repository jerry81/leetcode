/*
2179. Count Good Triplets in an Array
Hard
Topics
Companies
Hint
You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.



Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation:
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3).
Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).


Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1].
Seen this question in a real interview before?
1/5
Yes
No
Accepted
17.2K
Submissions
33.4K
Acceptance Rate
51.6%
*/
use std::collections::HashMap;

impl Solution {
  pub fn good_triplets(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
    let mut hm: HashMap<i32, usize> = HashMap::new();
    for i in 0..nums2.len() {
      *hm.entry(nums2[i]).or_insert(0) = i;
    }
    let mut nums: Vec<i32> = vec![];
    for i in nums1 {
      nums.push(hm[i]);
    }
    // num[j] represents position of item at num[j] in nums2
    // brute force would be count k = 0..j for nums[k] that are less than num[j] for each j, assign to left
    // then k = j+1..n count items where nums[k] > nums[j] and multiply left and right
    // fenwick (binary index tree) used to keep track of "frequencies" of values
    // frequency represents values that have been "seen"
    // rust provides FenwickTree::new()
    // with update(pos,val)
    // and query(pos,val)
    println!("nums is {:?}", nums);
    0
  }
}