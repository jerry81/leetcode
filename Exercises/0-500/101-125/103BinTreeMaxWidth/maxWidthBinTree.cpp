/*

662. Maximum Width of Binary Tree
Medium
6.6K
913
Companies
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the
leftmost and rightmost non-null nodes), where the null nodes between the
end-nodes that would be present in a complete binary tree extending down to that
level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4
(5,3,null,9). Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7
(6,null,null,null,null,null,7). Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).


Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
Accepted
252.8K
Submissions
615.6K
Acceptance Rate
41.1%

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

#include <queue>
using namespace std;
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
 public:
  int widthOfBinaryTree(TreeNode *root) {
    queue<pair<TreeNode*, long long int>> q;
    long long int maxW = 0;
    if (root != nullptr) {
      maxW = 1;
    }
    q.push({root,0});

    while (!q.empty()) {
      queue<pair<TreeNode*, long long int>> nq;
      long long int lp = -1;
      long long int rp = -1;
      int init = false;
      long long int minpos;
      while (!q.empty()) {
        if (!init) {
          init = true;
          minpos = q.front().second;
        }

        auto cur = q.front();
        q.pop();
        TreeNode *tn = cur.first;
        long long int nextpos = cur.second-minpos;
        if (tn->left != nullptr) {
          if (lp < 0) lp = 2*nextpos;

          if (2*nextpos > rp) rp = 2*nextpos;

          nq.push({tn->left, 2*nextpos});
        }

        if (tn->right != nullptr) {
          if (lp < 0) lp = 2*nextpos+1;
          if (2*nextpos+1 > rp) rp = 2*nextpos+1;

          nq.push({tn->right, 2*nextpos+1});
        }
      }
      if ((rp - lp + 1) > maxW) maxW = rp - lp + 1;
      if (!nq.empty()) q = nq;
    }
    return maxW;
  }
};

// too many cycles wasted on nulls
// new struct


/*

- seems like this case is testing that you break out and stop when there is no chance for width to get larger?
[0,0,0,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null,null,0,0,null]

*/