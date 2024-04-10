/*


1893. Check if All the Integers in a Range Are Covered
Easy
Topics
Companies
Hint
You are given a 2D integer array ranges and two integers left and right. Each ranges[i] = [starti, endi] represents an inclusive interval between starti and endi.

Return true if each integer in the inclusive range [left, right] is covered by at least one interval in ranges. Return false otherwise.

An integer x is covered by an interval ranges[i] = [starti, endi] if starti <= x <= endi.



Example 1:

Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
Output: true
Explanation: Every integer between 2 and 5 is covered:
- 2 is covered by the first range.
- 3 and 4 are covered by the second range.
- 5 is covered by the third range.
Example 2:

Input: ranges = [[1,10],[10,20]], left = 21, right = 21
Output: false
Explanation: 21 is not covered by any range.


Constraints:

1 <= ranges.length <= 50
1 <= starti <= endi <= 50
1 <= left <= right <= 50
Seen this question in a real interview before?
1/5
Yes
No
Accepted
41.2K
Submissions
83K
Acceptance Rate
49.7%

*/


impl Solution {
  pub fn is_covered(ranges: Vec<Vec<i32>>, left: i32, right: i32) -> bool {
    // merge ranges then compare
    let mut sorted_ranges = ranges.clone();
    sorted_ranges.sort_by(|a,b| { a[0].cmp(&b[0]) }); // Review: cmp takes the ref, cmp expects ref
    let mut merged_ranges: Vec<Vec<i32>> = vec![];
    let mut curleft = -1;
    let mut curright = -1;
    let sz = sorted_ranges.len();
    for i in 0..sz {
      let cur_range = &sorted_ranges[i]; // Review, the reference fixes moved issue
      let nl = cur_range[0];
      let nr = cur_range[1];
      if curleft < 0 {
        curleft = nl;
      }
      if curright < 0 {
        curright = nr;
      }
      if nl > (curright + 1) {
        // reset
         merged_ranges.push(vec![curleft, curright]);
         curleft = -1;
         curright = -1;
      } else {
        curright = nr;
      }
    }
    merged_ranges.push(vec![curleft, curright]);
    for v in merged_ranges {
      println!("merged range {} to {}", v[0], v[1]);
    }
    false
  }
}
