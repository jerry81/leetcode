/*

662. Maximum Width of Binary Tree
Medium
6.6K
913
Companies
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      queue<TreeNode*> q;
      int maxW = 0;
      int itemcount = (root != nullptr) ? 1: 0;
      q.push(root);

      while (itemcount > 0) {
        itemcount = 0;
        int curItem = 0;
        queue<TreeNode*> nq;
        int lp = -1;
        int rp = -1;
        while (!q.empty()) {
          TreeNode* tn = q.front();
          q.pop();
          if (tn == nullptr) {
            nq.push(nullptr);
            nq.push(nullptr);
          } else {
            if (tn->left != nullptr) {
              cout << "left found " << tn->left->val << endl;
              itemcount += 1;
              if (lp < 0) lp = nq.size();

              if ((int)nq.size() > rp) rp = (int)nq.size();
            }

            nq.push(tn->left);

            if (tn->right != nullptr) {
              cout << "right found " << tn->right->val << endl;
              itemcount += 1;
              if (lp < 0) lp = nq.size()+1;
              cout << "test " << nq.size()+1 << endl;
              cout << "vs rp " << rp << endl;
              if ((nq.size()+1) > rp) rp = (nq.size()+1);
            }

            nq.push(tn->right);
          }
        }
        cout << "rp is " << rp << endl;
        cout << "lp is " << lp << endl;
        if ((rp - lp) > maxW) maxW = rp - lp;
        q = nq;
      }
      return maxW;
    }
};

// bfs
//