/*

1971. Find if Path Exists in Graph
Easy
Topics
Companies
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.



Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.


Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
319.7K
Submissions
620K
Acceptance Rate
51.6%

*/

impl Solution {
  pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
    // union find
    // union find produces a vector of parents
    let mut parents: Vec<i32> = (0..n).collect();
    for e in edges {
      // union set them all
      let eater = e[0];
      let eaten = e[1];
      // get root of eater first
      let mut eater_root = eater;
      while parents[eater_root as usize] != eater_root {
        eater_root = parents[eater_root as usize];
      }
      let mut eaten_root = eaten;
      while parents[eaten_root as usize] != eaten_root {
        eaten_root = parents[eaten_root as usize];
      }
      if eaten_root != eater_root {
        parents[eaten_root as usize] = eater_root;
      }
    }
     // parents[source] == parents[destination] is WRONG
    // TIL: one more find is needed

    let mut source_root = source;
    while parents[source_root as usize] != source_root {
      source_root = parents[source_root as usize];
    }
    let mut destination_root = destination;
    while parents[destination_root as usize] != destination_root {
      destination_root = parents[destination_root as usize];
    }
    source_root == destination_root

  }
}