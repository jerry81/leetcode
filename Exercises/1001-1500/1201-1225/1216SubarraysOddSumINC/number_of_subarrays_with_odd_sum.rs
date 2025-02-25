/*


1524. Number of Sub-arrays With Odd Sum
Medium
Topics
Companies
Hint
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.



Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16


Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
69.5K
Submissions
139.6K
Acceptance Rate
49.8%

*/

impl Solution {
  pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
    let mut odd_count: i64 = 0;
    let mut even_count: i64 = 0;
    let mut is_even = true;

    for num in arr {
      is_even = num%2 == 0;

      if is_even {
        even_count+=1;
        even_count %= 1_000_000_007;
        even_count+= odd_count;
        even_count %= 1_000_000_007;
        odd_count += odd_count;
        odd_count %= 1_000_000_007;
      } else {
        odd_count+=1;
        odd_count %= 1_000_000_007;
        odd_count+= even_count;
        odd_count %= 1_000_000_007;
      }
    }

    (odd_count % 1_000_000_007) as i32
  }
}