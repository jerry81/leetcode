/*
Given the root of a binary tree, return the inorder traversal of its nodes'
values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/**
 * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };
 */

#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
 private:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}  // TIL: nullptr
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
  };

 public:
  vector<int> inorderTraversal(TreeNode *root) {
    unordered_map<int,bool> visited;
    vector<int> ret;
    vector<TreeNode*> stack;
    stack.push_back(root);
    visited[root->val] = true;
    while (!stack.empty()) {
      TreeNode* cur = stack.back();
      // left
      if (cur->left) {
        if (!visited[cur->left->val]) {
          stack.push_back(cur->left);
          continue;
        }
      }
      stack.pop_back();
      visited[cur->val] = true;
      ret.push_back(cur->val);
      if (cur->right && !visited[cur->right->val]) {
        stack.push_back(cur->right);
      }
    }
    return ret;
  }
};