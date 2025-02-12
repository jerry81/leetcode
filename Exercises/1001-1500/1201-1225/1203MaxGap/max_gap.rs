/*
164. Maximum Gap
Medium
Topics
Companies
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.



Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
256.1K
Submissions
529.4K
Acceptance Rate
48.4%
*/
impl Solution {
  pub fn maximum_gap(nums: Vec<i32>) -> i32 {
      if nums.len() < 2 {
          return 0;
      }

      let min_val = *nums.iter().min().unwrap();
      let max_val = *nums.iter().max().unwrap();

      if max_val == min_val {
          return 0; // All elements are the same
      }

      let bucket_size = ((max_val - min_val) / (nums.len() as i32 - 1)).max(1);
      let bucket_count = (max_val - min_val) / bucket_size + 1;

      let mut buckets: Vec<(Option<i32>, Option<i32>)> = vec![(None, None); bucket_count as usize];

      for &num in &nums {
          let bucket_index = ((num - min_val) / bucket_size) as usize;
          let (min_bucket, max_bucket) = &mut buckets[bucket_index];
          *min_bucket = Some(min_bucket.map_or(num, |v| v.min(num))); // first param is default if None is returned
          *max_bucket = Some(max_bucket.map_or(num, |v| v.max(num)));
      }

      let mut max_gap = 0;
      let mut previous_max = min_val;

      for &(min_bucket, max_bucket) in &buckets {
          if let Some(min) = min_bucket {
              max_gap = max_gap.max(min - previous_max);
              previous_max = max_bucket.unwrap(); // Update previous max
          }
      }

      max_gap
  }
}