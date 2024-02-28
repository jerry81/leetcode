/*

513. Find Bottom Left Tree Value
Medium
Topics
Companies
Given the root of a binary tree, return the leftmost value in the last row of
the tree.



Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
Seen this question in a real interview before?
1/4
Yes
No
Accepted
248.5K
Submissions
364.8K
Acceptance Rate
68.1%

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

#include <algorithm>
using namespace std;

class Solution {
  int res = -1;
  int depth(TreeNode *root) {
    if (root == nullptr) return 0;

    return max(1 + depth(root->left), 1 + depth(root->right));
  }
  int preorder(TreeNode *root, int curdepth, int tgtdepth) {
    if (root == nullptr) return -1;

    if (curdepth == tgtdepth) return root->val;

    int resl = preorder(root->left, 1+curdepth, tgtdepth);
    if (resl >= 0) return resl;
    return preorder(root->right, 1+curdepth, tgtdepth);
  }

 public:
  int findBottomLeftValue(TreeNode *root) {
    /// depth then max
    int mxd = depth(root);
    return preorder(root, 1, mxd);
  }
};