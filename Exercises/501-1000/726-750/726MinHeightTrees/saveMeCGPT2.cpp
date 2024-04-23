
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degrees(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degrees[u]++;
            degrees[v]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                leaves.push(i);
            }
        }

        while (n > 2) {
            int num_leaves = leaves.size();
            n -= num_leaves;
            for (int i = 0; i < num_leaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adj[leaf]) {
                    if (--degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};