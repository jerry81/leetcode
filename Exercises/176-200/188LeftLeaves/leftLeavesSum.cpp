/*

404. Sum of Left Leaves
Easy
4.6K
277
Companies
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
Accepted
441.6K
Submissions
776.3K
Acceptance Rate
56.9%

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
bool isLeaf(TreeNode* node) {
  return (node->left==nullptr && node->right==nullptr);
}
public:
    int sumOfLeftLeaves(TreeNode* root) {
      if (root==nullptr) return 0;
      int sum = 0;
      if (isLeaf(root->left)) {
        sum+=root->left->val;
      }

      return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};