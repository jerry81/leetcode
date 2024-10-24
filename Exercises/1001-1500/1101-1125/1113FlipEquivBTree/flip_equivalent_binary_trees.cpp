/*

951. Flip Equivalent Binary Trees
Medium
Topics
Companies
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.



Example 1:

Flipped Trees Diagram
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
Example 2:

Input: root1 = [], root2 = []
Output: true
Example 3:

Input: root1 = [], root2 = [1]
Output: false


Constraints:

The number of nodes in each tree is in the range [0, 100].
Each tree will have unique node values in the range [0, 99].
Seen this question in a real interview before?
1/5
Yes
No
Accepted
159K
Submissions
236K
Acceptance Rate
67.4%
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
bool double_dfs(TreeNode* a, TreeNode* b) {
  // 3 nodes to examine
  if (!a && b) return false;
  if (b && !a) return false;

  if (!a && !b) return true;

  if (a->val != b->val) return false;

  if (a->left != b->left && a->left == b->right && b->left == a->right) {
    return double_dfs(a->left, b->right) && double_dfs(a->right, b->left);
  }
  if (a->left == b->left && a->right == b->right) {
    return double_dfs(a->left, b->left) && double_dfs(a->right, b->right);
  }
  return true;
}
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
      // idea:  one side stays as baseline, the other side is flippable
      // keep a flag to keep track if flipped or not
      // walk both trees simultaneously
      // think about this:
      // unique values, so use val to compare the nodes
      if (!root1 && !root2) return true;
      if (!root1 && root2) return false;
      return double_dfs(root1, root2);
    }
};