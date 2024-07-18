
class Solution {
public:
    unordered_map<TreeNode *, vector<pair<TreeNode *, int>>> parents_dists;  // { child, map of {parent, distance} }
    unordered_map<TreeNode *, TreeNode *> parents;
    vector<TreeNode*> leaves;

    void push_parents_r(TreeNode *child, TreeNode *cur, int depth) {
        parents_dists[child].push_back({cur, depth});
        if (parents.find(cur) != parents.end())
            push_parents_r(child, parents[cur], depth + 1);
    }

    void r(TreeNode *cur, TreeNode *from) {
        if (cur == nullptr) return;

        if (from != nullptr) {
            parents[cur] = from;
            push_parents_r(cur, from, 1);
        }

        if (cur->left == nullptr && cur->right == nullptr) {
            leaves.push_back(cur);
        }

        r(cur->left, cur);
        r(cur->right, cur);
    }

    int countPairs(TreeNode *root, int distance) {
        r(root, nullptr);

        int res = 0;
        for (size_t i = 0; i < leaves.size(); ++i) { // cross compare
            for (size_t j = i + 1; j < leaves.size(); ++j) {
                int dist = calculateDistance(leaves[i], leaves[j]);
                if (dist <= distance) {
                    ++res;
                }
            }
        }
        return res;
    }

private:
    int calculateDistance(TreeNode* leaf1, TreeNode* leaf2) {
        unordered_map<TreeNode*, int> dist1; // make map for perf
        for (const auto& [node, dist] : parents_dists[leaf1]) {
            dist1[node] = dist;
        }

        int totalDistance = INT_MAX;
        for (const auto& [node, dist] : parents_dists[leaf2]) {
            if (dist1.find(node) != dist1.end()) { // O(1) find
                totalDistance = min(totalDistance, dist + dist1[node]);
            }
        }

        return totalDistance == INT_MAX ? 0 : totalDistance;
    }
};
