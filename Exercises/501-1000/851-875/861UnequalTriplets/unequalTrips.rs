/*

2475. Number of Unequal Triplets in Array
Easy
Topics
Companies
Hint
You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:

0 <= i < j < k < nums.length
nums[i], nums[j], and nums[k] are pairwise distinct.
In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
Return the number of triplets that meet the conditions.



Example 1:

Input: nums = [4,4,2,4,3]
Output: 3
Explanation: The following triplets meet the conditions:
- (0, 2, 4) because 4 != 2 != 3
- (1, 2, 4) because 4 != 2 != 3
- (2, 3, 4) because 2 != 4 != 3
Since there are 3 triplets, we return 3.
Note that (2, 0, 4) is not a valid triplet because 2 > 0.
Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: No triplets meet the conditions so we return 0.


Constraints:

3 <= nums.length <= 100
1 <= nums[i] <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
42K
Submissions
58.9K
Acceptance Rate
71.4%

*/

impl Solution {
  pub fn unequal_triplets(nums: Vec<i32>) -> i32 {
    // brute force it
    let sz = nums.len();
    let mut res = 0;
    for i in 0..sz {
      let iv = nums[i];
      for j in i+1..sz {
        if j == i { continue }

        let jv = nums[j];
        if jv == iv { continue }
        for k in j+1..sz {
          if k == j || k == i { continue }

          let kv = nums[k];

          if kv != jv && kv != iv {

            res+=1;
          }

        }
      }
    }
    res
  }
}