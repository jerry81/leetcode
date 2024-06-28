#include <vector>
#include <numeric>

using namespace std;
class Solution {
 public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    // Step 1: Count degrees
    vector<int> degree(n, 0);
    for (const auto& road : roads) {
      degree[road[0]]++;
      degree[road[1]]++;
    }

    // Step 2: Sort degrees in descending order
    vector<int> indices(n);
    iota(indices.begin(), indices.end(),
         0);  // TIL: iota - fill vector from x to size, part of numeric
    sort(indices.begin(), indices.end(),
         [&degree](int a, int b) { return degree[a] > degree[b]; });

    // Step 3: Assign values based on sorted indices
    vector<int> importance(n);
    for (int i = 0; i < n; ++i) {
      importance[indices[i]] = n - i;
    }

    // Step 4: Calculate total importance
    long long totalImportance = 0;
    for (const auto& road : roads) {
      totalImportance += importance[road[0]] + importance[road[1]];
    }

    return totalImportance;
  }
};