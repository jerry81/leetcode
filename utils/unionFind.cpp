#include <vector>

using namespace std;


class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.assign(n, 0);

        // Initialize each element as its own parent
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find operation with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union operation with rank optimization
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y) {
            if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
            } else if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
            } else {
                parent[root_y] = root_x;
                rank[root_x]++;
            }
        }
    }

    // Check if two elements are in the same set
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> parent; // Parent array for each element
    vector<int> rank;   // Rank of each element for rank optimization
};