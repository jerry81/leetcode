#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};

        auto leftDistances = dfs(node->left, distance, result);
        auto rightDistances = dfs(node->right, distance, result);

        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    result++;
                }
            }
        }

        vector<int> newDistances;
        for (int ld : leftDistances) {
            if (ld + 1 < distance) {
                newDistances.push_back(ld + 1);
            }
        }
        for (int rd : rightDistances) {
            if (rd + 1 < distance) {
                newDistances.push_back(rd + 1);
            }
        }

        return newDistances;
    }
};