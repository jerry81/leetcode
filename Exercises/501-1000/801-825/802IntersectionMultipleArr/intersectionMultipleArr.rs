/*
2248. Intersection of Multiple Arrays
Easy
Topics
Companies
Hint
Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.


Example 1:

Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation:
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
Example 2:

Input: nums = [[1,2,3],[4,5,6]]
Output: []
Explanation:
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].


Constraints:

1 <= nums.length <= 1000
1 <= sum(nums[i].length) <= 1000
1 <= nums[i][j] <= 1000
All the values of nums[i] are unique.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
77.5K
Submissions
113.9K
Acceptance Rate
68.0%
*/

use std::collections::HashMap;
impl Solution {
  pub fn intersection(nums: Vec<Vec<i32>>) -> Vec<i32> {
    // Hashmap , gather frequencies
    let mut hm: HashMap<i32,i32> = HashMap::new();
    let sz = nums.len();
    for nv in nums {
      for n in nv {
        *hm.entry(n).or_insert(0) +=1;
      }
    }

    // find the items common to each array
    let mut to_be_sorted:Vec<i32> = Vec::new();
    for (k,v) in hm {
      if v == sz as i32 {
        to_be_sorted.push(k);
      }
    }
     // sort and return
    to_be_sorted.sort();
    to_be_sorted
  }
}

