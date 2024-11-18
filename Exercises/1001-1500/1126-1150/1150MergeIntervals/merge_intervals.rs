/*


56. Merge Intervals
Medium
Topics
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2.8M
Submissions
5.7M
Acceptance Rate
48.2%

*/

impl Solution {
  pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    // sort by starting time

    let mut res: Vec<Vec<i32>> = vec![];
    let mut sorted: Vec<Vec<i32>> = intervals.clone();
    sorted.sort_by(|a,b| { a[0].cmp(&b[0])});
    let mut curstart = sorted[0][0];
    let mut curend = sorted[0][1];

    // compare adjacent
    for interval in sorted.iter().skip(1) {
      if interval[0] > curend {
        res.push(vec![curstart, curend]);
        curstart = interval[0];
        curend = interval[1];
        continue;
      }
      curend = curend.max(interval[1]);
    }
    res.push(vec![curstart, curend]);
    res
  }
}