impl Solution {
  pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let mut graph: Vec<Vec<i32>> = vec![vec![]; n as usize];
    let mut res = vec![];

    // Initialize the graph with the initial roads
    for i in 0..n - 1 {
      graph[i as usize].push(i + 1);
    }

    for q in queries {
      let (u, v) = (q[0], q[1]);
      graph[u as usize].push(v); // Add the new road

      // Perform BFS to find the shortest path from 0 to n-1
      let mut queue = vec![0];
      let mut distances = vec![-1; n as usize];
      distances[0] = 0;

      while !queue.is_empty() {
        let current = queue.remove(0);
        for &neighbor in &graph[current as usize] {
          if distances[neighbor as usize] == -1 { // Not visited
            distances[neighbor as usize] = distances[current as usize] + 1;
            queue.push(neighbor);
          }
        }
      }

      res.push(distances[(n - 1) as usize]);
    }
    res
  }
}