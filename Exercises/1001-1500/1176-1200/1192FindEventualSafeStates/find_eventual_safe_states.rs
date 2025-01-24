/*

802. Find Eventual Safe States
Medium
Topics
Companies
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.



Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.


Constraints:

n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].
Seen this question in a real interview before?
1/5
Yes
No
Accepted
338.4K
Submissions
513.9K
Acceptance Rate
65.8%

*/
impl Solution {
  pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
  let mut safe_nodes: Vec<i32> = vec![];
  let node_count = graph.len();
  for i in 0..node_count {
    if graph[i].is_empty() {
      safe_nodes.push(i as i32);
    }
  }
  // tally m/n
  let mut parent = vec![0; graph.len()];
  let mut rank = vec![0; graph.len()];

  // Find function with path compression
  fn find(node: usize, parent: &mut Vec<usize>) -> usize {
    if parent[node] != node {
      parent[node] = find(parent[node], parent);
    }
    parent[node]
  }

  // Union function
  fn union(node1: usize, node2: usize, parent: &mut Vec<usize>, rank: &mut Vec<usize>) {
    let root1 = find(node1, parent);
    let root2 = find(node2, parent);
    if root1 != root2 {
      if rank[root1] > rank[root2] {
        parent[root2] = root1;
      } else if rank[root1] < rank[root2] {
        parent[root1] = root2;
      } else {
        parent[root2] = root1;
        rank[root1] += 1;
      }
    }
  }

  // Initialize parent for each node
  for i in 0..graph.len() {
    parent[i] = i;
  }

  // Union nodes based on the graph
  for (i, edges) in graph.iter().enumerate() {
    for &edge in edges {
      union(i, edge as usize, &mut parent, &mut rank);
    }
  }

  // Identify safe nodes
  let mut safe_nodes: Vec<i32> = vec![];
  for i in 0..graph.len() {
    if find(i, &mut parent) == i {
      safe_nodes.push(i as i32);
    }
  }

  println!("safe nodes are {:?}", safe_nodes);
  safe_nodes.sort(); // Ensure the output is sorted
  safe_nodes
}
}

// Helper functions for disjoint set
fn find(parent: &mut Vec<usize>, x: usize) -> usize {
  if parent[x] != x {
      parent[x] = find(parent, parent[x]);
  }
  parent[x]
}

fn union(parent: &mut Vec<usize>, size: &mut Vec<usize>, x: usize, y: usize) {
  let root_x = find(parent, x);
  let root_y = find(parent, y);
  if root_x != root_y {
      if size[root_x] < size[root_y] {
          parent[root_x] = root_y;
          size[root_y] += size[root_x];
      } else {
          parent[root_y] = root_x;
          size[root_x] += size[root_y];
      }
  }
}