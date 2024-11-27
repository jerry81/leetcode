/*

3243. Shortest Distance After Road Addition Queries I
Medium
Topics
Companies
Hint
You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.



Example 1:

Input: n = 5, queries = [[2,4],[0,2],[0,4]]

Output: [3,2,1]

Explanation:



After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.



After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.



After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

Example 2:

Input: n = 4, queries = [[0,3],[0,2]]

Output: [1,1]

Explanation:



After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.



After the addition of the road from 0 to 2, the length of the shortest path remains 1.



Constraints:

3 <= n <= 500
1 <= queries.length <= 500
queries[i].length == 2
0 <= queries[i][0] < queries[i][1] < n
1 < queries[i][1] - queries[i][0]
There are no repeated roads among the queries.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
31.9K
Submissions
64.3K
Acceptance Rate
49.7%

*/

impl Solution {
  pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let mut dists: Vec<i32> = (0..n).rev().collect();
    let mut sorted_queries = queries.clone();
    sorted_queries.sort_by_key(|q| -q[0]);
    let mut res = vec![];
    for q in sorted_queries {
      let mut beginidx = q[0] as usize;
      let mut endidx = q[1] as usize;
      for i in (0..=beginidx).rev() {
        dists[i] = (dists[endidx]+1).min(dists[i]);
        endidx = i;
      }
      res.push(dists[0]);
    }
    res
  }
}
/*
this does not take care of the 2 jumps in a row case
try: first sort desc by start
*/

 // start
 // n = 5
 /*
   4,3,2,1,0
   add [2,4]
   3,2,1,1,0
   add [0,2]
   2,3,1,1,0
   add [0,4]
   1,2,1,1,0
 */