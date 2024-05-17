/*

1325. Delete Leaves With a Given Value
Medium
Topics
Companies
Hint
Given a binary tree root and an integer target, delete all the leaf nodes with
value target.

Note that once you delete a leaf node with value target, if its parent node
becomes a leaf node and has the value target, it should also be deleted (you
need to continue doing that until you cannot).



Example 1:



Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in
left). After removing, new nodes become leaf nodes with value (target = 2)
(Picture in center). Example 2:



Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
Example 3:



Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each
step.


Constraints:

The number of nodes in the tree is in the range [1, 3000].
1 <= Node.val, target <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
109.6K
Submissions
146.8K
Acceptance Rate
74.7%

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
 void r(TreeNode *cur, int tgt) {
   if (!cur) return;

   bool leaf = true;
   if (cur->left != nullptr) {
     r(cur->left, tgt);
     leaf = false;
   }

   if (cur->right != nullptr) {
     r(cur->right, tgt);
     leaf = false;
   }

    if (leaf && cur->val == tgt) {
      cur->left = nullptr;
      cur->right = nullptr;
    }
 }
 public:
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    r(root,target);
    return root;
  }
};