
struct UnionFind {
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            parent[pa] = pb;
            return true;
        }
        return false;
    }

    bool traversable() {
        unordered_set<int> roots;
        for (int i = 0; i < parent.size(); ++i) {
            roots.insert(find(i));
        }
        return roots.size() == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n);
        UnionFind bob(n);
        int usedEdges = 0;

        // Process type 3 edges first (usable by both Alice and Bob)
        for (const vector<int>& edge : edges) {
            if (edge[0] == 3) {
                int u = edge[1] - 1;
                int v = edge[2] - 1;
                if (alice.unite(u, v) | bob.unite(u, v)) {
                    usedEdges++;
                }
            }
        }

        // Process type 1 (Alice) and type 2 (Bob) edges
        for (const vector<int>& edge : edges) {
            int type = edge[0];
            int u = edge[1] - 1;
            int v = edge[2] - 1;
            if (type == 1) {
                if (alice.unite(u, v)) {
                    usedEdges++;
                }
            } else if (type == 2) {
                if (bob.unite(u, v)) {
                    usedEdges++;
                }
            }
        }

        // Check if both graphs are fully traversable
        if (!alice.traversable() || !bob.traversable()) {
            return -1;
        }

        // Calculate maximum number of edges that can be removed
        return edges.size() - usedEdges;
    }
};