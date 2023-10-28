/*

1037. Valid Boomerang
Easy
381
507
Companies
Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.

A boomerang is a set of three points that are all distinct and not in a straight line.



Example 1:

Input: points = [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: false


Constraints:

points.length == 3
points[i].length == 2
0 <= xi, yi <= 100
Accepted
46.2K
Submissions
125.5K
Acceptance Rate
36.8%

*/

impl Solution {
  fn calculate_slope(x1: i32, x2: i32, y1: i32, y2: i32) -> f64 {
    if x1 == x2 {
        f64::INFINITY
    } else {
        f64::from(y2 - y1) / f64::from(x2 - x1)
    }
}
  fn is_distinct(points: &Vec<Vec<i32>>) -> bool {
    let pt1 = &points[0]; // this is known as borrowing aka creating references
    let pt2 = &points[1];
    let pt3 = &points[2];
    if pt1[0] == pt2[0] && pt1[1] == pt2[1] {
      return false;
    }
    if pt1[0] == pt3[0] && pt1[1] == pt3[1] {
      return false;
    }
    if pt2[0] == pt3[0] && pt2[1] == pt3[1] {
      return false;
    }
    return true;
  }

  fn on_line(points: &Vec<Vec<i32>>) -> bool {
    let mut sorted = points.clone();
    sorted.sort_by(|a, b| a[0].cmp(&b[0]));
    let pt1 = &sorted[0];
    let pt2 = &sorted[1];
    let pt3 = &sorted[2];

    let slope1_to_2 = Solution::calculate_slope(pt1[0], pt2[0], pt1[1], pt2[1]);
    let slope2_to_3 = Solution::calculate_slope(pt2[0], pt3[0], pt2[1], pt3[1]);

    slope1_to_2 == slope2_to_3
  }

  pub fn is_boomerang(points: Vec<Vec<i32>>) -> bool {
    // check distinct
    if !Solution::is_distinct(&points) { return false; }
    // check line
    if Solution::on_line(&points) { return false; }

    true
  }
}