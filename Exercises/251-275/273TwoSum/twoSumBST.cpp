/*

653. Two Sum IV - Input is a BST
Easy
6.3K
250
Companies
Given the root of a binary search tree and an integer k, return true if there
exist two elements in the BST such that their sum is equal to k, or false
otherwise.



Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
Accepted
480.8K
Submissions
787.1K
Acceptance Rate
61.1%

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

class Solution {
  bool find(TreeNode *root, int k) {
    if (root == nullptr) return false;
    int cur = root->val;
    if (cur == k) return true;

    if (k < cur) {
      return find(root->left, k);
    } else {
      return find(root->right, k);
    }
  }

  bool r(TreeNode *root, int k, TreeNode *orig) {
    if (root == nullptr) return false;
    int cur = root->val;
    int diff = k - cur;
    if ((diff * 2) == k)
      return r(root->left, k, orig) || r(root->right, k, orig);
    return find(orig, diff) || r(root->left, k, orig) ||
           r(root->right, k, orig);
  }

 public:
  bool findTarget(TreeNode *root, int k) { return r(root, k, root); }
};