
impl Solution {
  pub fn most_profitable_path(edges: Vec<Vec<i32>>, bob: i32, amount: Vec<i32>) -> i32 {
      use std::collections::VecDeque; // TIL: use in a subscope

      let n = amount.len();
      let mut graph = vec![vec![]; n];
      for edge in &edges {
          let (u, v) = (edge[0] as usize, edge[1] as usize); // tuples
          graph[u].push(v);
          graph[v].push(u);
      }

      // Step 1: Find Bob's path from bob to root (0)
      let mut parent = vec![-1; n];
      let mut queue = VecDeque::new();
      queue.push_back(bob as usize);
      parent[bob as usize] = bob;

      while let Some(node) = queue.pop_front() {
          for &next in &graph[node] {
              if parent[next] == -1 && next != bob as usize {
                  parent[next] = node as i32;
                  queue.push_back(next);
              }
          }
      }

      let mut bob_path = vec![];
      let mut node = 0;
      while node != bob as usize {
          bob_path.push(node);
          node = parent[node] as usize;
      }
      bob_path.push(bob as usize);

      // Step 2: DFS to calculate max profit along Alice's path
      fn dfs(
          graph: &Vec<Vec<usize>>,
          amount: &Vec<i32>,
          visited: &mut Vec<bool>,
          node: usize,
          depth: i32,
          bob_depth: &Vec<i32>,
      ) -> i32 {
          visited[node] = true;
          let mut profit = if depth < bob_depth[node] {
              amount[node]
          } else if depth == bob_depth[node] {
              amount[node] / 2
          } else {
              0
          };

          let mut max_subprofit = i32::MIN;
          for &next in &graph[node] {
              if !visited[next] {
                  max_subprofit = max_subprofit.max(dfs(graph, amount, visited, next, depth + 1, bob_depth));
              }
          }

          if max_subprofit == i32::MIN {
              profit // Leaf node
          } else {
              profit + max_subprofit
          }
      }

      // Bob's depth from the root
      let mut bob_depth = vec![i32::MAX; n];
      let mut cur_depth = 0;
      for &node in bob_path.iter().rev() {
          bob_depth[node] = cur_depth;
          cur_depth += 1;
      }

      let mut visited = vec![false; n];
      dfs(&graph, &amount, &mut visited, 0, 0, &bob_depth)
  }
}
