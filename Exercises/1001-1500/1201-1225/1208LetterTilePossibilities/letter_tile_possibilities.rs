/*

1079. Letter Tile Possibilities
Medium
Topics
Companies
Hint
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.



Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1


Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
116.4K
Submissions
150.9K
Acceptance Rate
77.2%

*/

use std::collections::HashSet;

impl Solution {
  pub fn num_tile_possibilities(tiles: String) -> i32 {
    // bounds small, brute force it
    let mut res: HashSet<String> = HashSet::new();
    res.len() as i32
  }
}

/*
n = 3
ABC
1
2
3
12
13
21
31
23
32
123
132
213
231
312
321
14
l = 1
3 choices 1 position
l = 2
3 choices 2 positions
_ _
3 * 2 = 6
_ _ _ also 6
3 * 2 * 1 = 6

n = 6
3,2,1

AAB

A
B
AB
BA
AA
AAB
ABA
BAA

_
# unique

2 * 1 but missing 1 1
_ _

*/