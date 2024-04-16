/*

623. Add One Row to Tree
Medium
Topics
Companies
Given the root of a binary tree and two integers val and depth, add a row of
nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1,
create two tree nodes with value val as cur's left subtree root and right
subtree root. cur's original left subtree should be the left subtree of the new
left subtree root. cur's original right subtree should be the right subtree of
the new right subtree root. If depth == 1 that means there is no depth depth - 1
at all, then create a tree node with value val as the new root of the whole
original tree, and the original tree is the new root's left subtree.


Example 1:


Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]
Example 2:


Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]


Constraints:

The number of nodes in the tree is in the range [1, 104].
The depth of the tree is in the range [1, 104].
-100 <= Node.val <= 100
-105 <= val <= 105
1 <= depth <= the depth of tree + 1
Seen this question in a real interview before?
1/5
Yes
No
Accepted
169.6K
Submissions
282.4K
Acceptance Rate
60.1%

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

#include <queue>

using namespace std;

class Solution {
 public:
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
      TreeNode *ret = new TreeNode(val);
      ret->left = root;
      return ret;
    }

    queue<TreeNode*> q;
    // level order
    // step one: iterate level order
    // step 2: create new roots
    // step 3: deal with nulls
    q.push(root);
    int c_level = 1;
    while (!q.empty()) {
      queue<TreeNode*> nq;
      while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        if (!cur) continue;


        if (c_level == depth-1) {
          TreeNode* inserted = new TreeNode(val);
          TreeNode* inserted2 = new TreeNode(val);
          inserted->left = cur->left;
          inserted2->right = cur->right;
          cur->left = inserted;
          cur->right = inserted2;
          nq.push(inserted->left);
          nq.push(inserted->right);
        } else {
          nq.push(cur->left);
          nq.push(cur->right);
        }

      }
      q = nq;
      c_level++;
    }
    return root;
  }
};