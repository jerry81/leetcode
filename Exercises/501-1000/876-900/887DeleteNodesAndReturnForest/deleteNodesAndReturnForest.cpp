/*

1110. Delete Nodes And Return Forest
Medium
Topics
Companies
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a
disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result
in any order.



Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]


Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
241.8K
Submissions
346.9K

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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, TreeNode *> parent_map;
  unordered_map<int, TreeNode *> nodes;

  void populate_parents(TreeNode *cur, TreeNode *from) {
    if (cur == nullptr) return;

    nodes[cur->val] = cur;

    if (from != nullptr) parent_map[cur->val] = from;

    populate_parents(cur->left, cur);
    populate_parents(cur->right, cur);
  }

 public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    // how we know if child becomes orphaned?
    // parent map like yesterday
    populate_parents(root, nullptr);
    for (int deleted : to_delete) {
      if (parent_map.find(deleted) != parent_map.end()) {
        TreeNode *parent_of_deleted = nodes[parent_map[deleted]->val];
        if (parent_of_deleted->left == nodes[deleted]) {
          parent_of_deleted->left = nullptr;
        } else {
          parent_of_deleted->right = nullptr;
        }
      }
      if (nodes[deleted]->left != nullptr) {
        parent_map.erase(nodes[deleted]->left->val);
      }
      if (nodes[deleted]->right != nullptr) {
        parent_map.erase(nodes[deleted]->right->val);
      }
      delete nodes[deleted];
      nodes.erase(deleted);
    }
    vector<TreeNode *> res;
    for (auto [k, v] : nodes) {
      if (parent_map.find(k) == parent_map.end()) {
        res.push_back(v);
      }
    }
    return res;
  }
};