/*

1496. Path Crossing
Easy
1.1K
30
Companies
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.



Example 1:


Input: path = "NES"
Output: false
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:


Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.


Constraints:

1 <= path.length <= 104
path[i] is either 'N', 'S', 'E', or 'W'.
Accepted
90.6K
Submissions
150.6K
Acceptance Rate
60.2%
*/

use std::collections::HashSet; // LC runtime wants this

impl Solution {
  pub fn hsh(y:i32, x:i32) -> String {
    return format!("{},{}", y,x);
  }

  pub fn is_path_crossing(path: String) -> bool {

    let mut hash_set: HashSet<String> = HashSet::new();
    let mut cy = 0;
    let mut cx = 0;
    hash_set.insert(Solution::hsh(0,0));
    for let c in path.chars() {
      if c == 'N' {
        cy-=1;
      } else if c == 'S' {
        cy+=1;
      } else if c == 'W' {
        cx-=1;
      } else {
        cx+=1;
      }
      let ch = hsh(cy,cx);
      if hash_set.contains(ch) {
        return false;
      }
    }

    true

  }
}