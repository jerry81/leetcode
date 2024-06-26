/*

2379. Minimum Recolors to Get K Consecutive Black Blocks
Easy
Topics
Companies
Hint
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.



Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW".
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
Example 2:

Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.


Constraints:

n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n
Seen this question in a real interview before?
1/5
Yes
No
Accepted
52.8K
Submissions
89.8K
Acceptance Rate
58.8%

*/

impl Solution {
  fn countBlacks(blocks: &str) -> i32 {
    let mut res = 0;
    for c in blocks.chars() {
      if c == 'B' { res+=1; }
    }
    res
  }
  fn getWhites(blocks: &str) -> Vec<usize> {
    let mut res = vec![];
    for i in 0..blocks.len() {
      if blocks.chars().nth(i).unwrap() == 'W' { res.push(i); }

    }
    res
  }
  pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
    // brute - find all white blocks, recound every time
    let widx = Solution::getWhites(&blocks);
    for i in widx {
      println!("{}", i);
    }
    0
  }
}