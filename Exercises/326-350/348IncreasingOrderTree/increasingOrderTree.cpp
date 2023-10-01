/*

897. Increasing Order Search Tree
Easy
4.1K
659
Companies
Given the root of a binary search tree, rearrange the tree in in-order so that
the leftmost node in the tree is now the root of the tree, and every node has no
left child and only one right child.



Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]


Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
Accepted
262.2K
Submissions
334.9K
Acceptance Rate
78.3%

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

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
  vector<int> seq;
  void r(TreeNode* root) {
    if (root == nullptr) return;
    r(root->left);
    seq.push_back(root->val);
    r(root->right);
  }

 public:
  TreeNode* increasingBST(TreeNode* root) {
    r(root);
    TreeNode* ret;
    TreeNode* cur;
    for (int i : seq) {
      TreeNode* nxt = new TreeNode(i);
      if (ret == nullptr) {
        ret = nxt;
        cur = ret;
      } else {
        cur->right = nxt;
        cur = cur->right;
      }
    }
    return ret;
  }
};