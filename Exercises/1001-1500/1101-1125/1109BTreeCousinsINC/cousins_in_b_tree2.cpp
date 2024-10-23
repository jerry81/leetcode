/*
2641. Cousins in Binary Tree II
Medium
Topics
Companies
Hint
Given the root of a binary tree, replace the value of each node in the tree with
the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with
different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root
node to it.



Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree
after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree
after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.


Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
26.2K
Submissions
37.9K
Acceptance Rate
69.0%
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <unordered_map>
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
  vector<vector<TreeNode *>> level_nodes;
  vector<int> level_sums;
  unordered_map<TreeNode *, int> direct_children_sums;
  unordered_map<TreeNode *, TreeNode*> parents;
  void dfs(TreeNode *cur, int lvl, TreeNode *parent) {
    if (cur) {
      level_sums[lvl] += cur->val;
      level_nodes[lvl].push_back(cur);
      dfs(cur->left, lvl + 1, cur);
      dfs(cur->right, lvl + 1, cur);
      if (parent) {
        direct_children_sums[parent] += cur->val;
        parents[cur] = parent;
      }
    }
  }

  void dfs2(TreeNode *cur, int lvl) {
    if (cur) {
      cur->val = level_sums[lvl] - direct_children_sums[parents[cur]];
      dfs2(cur->left, lvl + 1);
      dfs2(cur->right, lvl + 1);
    }
  }

 public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    // one pass - use map to store the level nodes
    level_nodes.resize(10);
    level_sums.resize(10);
    dfs(root, 0, nullptr);
    dfs2(root, 0);
    root->val = 0;
    return root;
  }
};