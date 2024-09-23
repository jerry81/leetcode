/*

3024. Type of Triangle
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

A triangle is called equilateral if it has all sides of equal length.
A triangle is called isosceles if it has exactly two sides of equal length.
A triangle is called scalene if all its sides are of different lengths.
Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.



Example 1:

Input: nums = [3,3,3]
Output: "equilateral"
Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
Example 2:

Input: nums = [3,4,5]
Output: "scalene"
Explanation:
nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3.
Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
As all the sides are of different lengths, it will form a scalene triangle.


Constraints:

nums.length == 3
1 <= nums[i] <= 100

Seen this question in a real interview before?
1/5
Yes
No
Accepted
48.5K
Submissions
126.4K
Acceptance Rate
38.4%

*/

use std::collections::HashMap;

impl Solution {
  fn is_triangle_possible(a: i32, b: i32, c: i32) -> bool {
    a + b > c && a + c > b && b + c > a
  }
  pub fn triangle_type(nums: Vec<i32>) -> String {
    let mut hm:HashMap<i32,i32> = HashMap::new();
    for i in &nums {
      *hm.entry(i).or_insert(0) +=1;
    }

    if !Solution::is_triangle_possible(nums[0], nums[1], nums[2]) { return "none".to_string() }

    // check if triangle is possible

    match hm.len() {
      1 => { return "equilateral".to_string() },
      2 => { return "isosceles".to_string() },
      3 => { return "scalene".to_string() },
      _ => { return "none".to_string() }
    }
  }
}