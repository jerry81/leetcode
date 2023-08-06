/*

572. Subtree of Another Tree
Easy
7.5K
430
Companies
Given the roots of two binary trees root and subRoot, return true if there is a
subtree of root with the same structure and node values of subRoot and false
otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and
all of this node's descendants. The tree tree could also be considered as a
subtree of itself.



Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false


Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104
Accepted
693.5K
Submissions
1.5M
Acceptance Rate
46.8%

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
  TreeNode *find(TreeNode *root, int tgt) {
    if (root->val == tgt) return root;

    if (root == nullptr) return nullptr;

    TreeNode *res;

    res = find(root->left, tgt);
    if (res != nullptr) return res;

    res = find(root->right, tgt);

    return res;
  }

  bool eq(TreeNode *a, TreeNode *b) {
    if (a==nullptr && b==nullptr) return true;
    if (a==nullptr && b!=nullptr) return false;
    if (b==nullptr && a!=nullptr) return false;
    if (a->val != b->val) return false;
    if (a->val == b->val) {
      return eq(a->left, b->left) && eq(a->right,b->right);
    }

  }

 public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    TreeNode* start = find(root, subRoot->val);
    if (start == nullptr) return false;

    return eq(start,subRoot);
  }
};