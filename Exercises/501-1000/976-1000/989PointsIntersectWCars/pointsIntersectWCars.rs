/*

2848. Points That Intersect With Cars
Easy
Topics
Companies
Hint
You are given a 0-indexed 2D integer array nums representing the coordinates of the cars parking on a number line. For any index i, nums[i] = [starti, endi] where starti is the starting point of the ith car and endi is the ending point of the ith car.

Return the number of integer points on the line that are covered with any part of a car.



Example 1:

Input: nums = [[3,6],[1,5],[4,7]]
Output: 7
Explanation: All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.
Example 2:

Input: nums = [[1,3],[5,8]]
Output: 7
Explanation: Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.


Constraints:

1 <= nums.length <= 100
nums[i].length == 2
1 <= starti <= endi <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
50.7K
Submissions
67.2K
Acceptance Rate
75.5%

*/

impl Solution {
  pub fn number_of_points(nums: Vec<Vec<i32>>) -> i32 {
    // get max end
    let mut range:Vec<bool> = vec![false;101];
    let mut res = 0;
    for car in nums {
      for idx in car[0]..=car[1] {
        if !range[idx as usize] {
          range[idx as usize] = true;
          res += 1;
        }
      }
    }
    res
  }
}