
class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    unordered_map<int, vector<pair<int, int>>> graph;

    // Build the adjacency list
    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];
      graph[u].push_back({v, w});
      graph[v].push_back({u, w});
    }

    int minReachableCities = INT_MAX;
    int resultCity = -1;

    for (int i = 0; i < n; ++i) {
      int reachableCities = dijkstra(n, graph, i, distanceThreshold);
      // If there is a tie, choose the city with the greatest number
      if (reachableCities <= minReachableCities) {
        minReachableCities = reachableCities;
        resultCity = i;
      }
    }

    return resultCity;
  }

 private:
  int dijkstra(int n, unordered_map<int, vector<pair<int, int>>>& graph, int start, int distanceThreshold) {
    vector<int> distances(n, INT_MAX);
    distances[start] = 0;

    // Min-heap priority queue, storing pairs of (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
      auto [currDist, node] = pq.top();
      pq.pop();

      if (currDist > distances[node]) {
        continue;
      }

      for (auto& [neighbor, weight] : graph[node]) {
        int newDist = currDist + weight;
        if (newDist < distances[neighbor]) {
          distances[neighbor] = newDist;
          pq.push({newDist, neighbor});
        }
      }
    }

    // Count cities within the distance threshold
    int count = 0;
    for (int dist : distances) {
      if (dist <= distanceThreshold) {
        count++;
      }
    }

    return count - 1;  // Exclude the starting city itself
  }
};