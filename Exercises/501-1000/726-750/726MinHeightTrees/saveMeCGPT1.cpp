
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        unordered_map<int, int> degrees;
        for (vector<int>& e : edges) {
            degrees[e[0]]++;
            degrees[e[1]]++;
        }

        vector<int> res;
        while (degrees.size() > 2) {
            vector<int> to_remove;
            for (auto it = degrees.begin(); it != degrees.end(); ) {
                if (it->second <= 1) {
                    to_remove.push_back(it->first);
                    it = degrees.erase(it);
                } else {
                    ++it;
                }
            }

            vector<vector<int>> nxt_edges;
            for (vector<int>& e : edges) {
                if (find(to_remove.begin(), to_remove.end(), e[0]) == to_remove.end() &&
                    find(to_remove.begin(), to_remove.end(), e[1]) == to_remove.end()) {
                    nxt_edges.push_back(e);
                } else {
                    if (degrees.find(e[0]) != degrees.end() && find(to_remove.begin(), to_remove.end(), e[0]) == to_remove.end()) {
                        degrees[e[0]]--;
                    }
                    if (degrees.find(e[1]) != degrees.end() && find(to_remove.begin(), to_remove.end(), e[1]) == to_remove.end()) {
                        degrees[e[1]]--;
                    }
                }
            }
            edges = move(nxt_edges);
        }

        for (auto& kv : degrees) {
            res.push_back(kv.first);
        }
        return res;
    }
};