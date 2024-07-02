/*

2418. Sort the People
Easy
Topics
Companies
Hint
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.



Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.


Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
142.3K
Submissions
177.6K
Acceptance Rate
80.1%

*/


impl Solution {
  pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
   let mut heightPairs :  Vec<(&str, i32)>  = Vec::new();
   let mut res: Vec<String> = Vec::new();
   let sz = heights.len();
   for idx in 0..sz {
     heightPairs.push((&names[idx],heights[idx]));
   }

   heightPairs.sort_by(|a,b| { b.1.cmp(&a.1) }).map(|item| {item.0}).collect()

  }
}