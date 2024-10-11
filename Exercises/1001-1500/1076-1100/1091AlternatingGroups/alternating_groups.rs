/*

3206. Alternating Groups I
Easy
Topics
Companies
Hint
There is a circle of red and blue tiles. You are given an array of integers colors. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from its left and right tiles) is called an alternating group.

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.



Example 1:

Input: colors = [1,1,1]

Output: 0

Explanation:



Example 2:

Input: colors = [0,1,0,0,1]

Output: 3

Explanation:



Alternating groups:





Constraints:

3 <= colors.length <= 100
0 <= colors[i] <= 1
Seen this question in a real interview before?
1/5
Yes
No
Accepted
48.3K
Submissions
71.9K
Acceptance Rate
67.2%

*/

impl Solution {
  pub fn number_of_alternating_groups(colors: Vec<i32>) -> i32 {
    let mut colors_extended:Vec<i32> = colors.clone();
    colors_extended.push(colors[0]);
    colors_extended.push(colors[1]);
    let mut n = colors_extended.len();
    let mut res = 0;
    for i in 0..n-2 {
      if colors_extended[i] != colors_extended[i+1] && colors_extended[i+2] != colors_extended[i+1] {
        res+=1;
      }
    }
    res
  }
}