/*


979. Distribute Coins in Binary Tree
Medium
Topics
Companies
You are given the root of a binary tree with n nodes where each node in the tree
has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to
another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one
coin.



Example 1:


Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and
one coin to its right child. Example 2:


Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root
[taking two moves]. Then, we move one coin from the root of the tree to the
right child.


Constraints:

The number of nodes in the tree is n.
1 <= n <= 100
0 <= Node.val <= n
The sum of all Node.val is n.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
119.5K
Submissions
163.7K
Acceptance Rate
73.0%

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

#include <vector>

using namespace std;

class Solution {
  int mv = 0;
  int r(TreeNode *root) {
    if (root == nullptr) return 0;

    TreeNode *lt = root->left;
    TreeNode *rt = root->right;
    int lDiff = r(lt);
    int rDiff = r(rt);
    mv += abs(lDiff);  // this updates the tally of the operations made.
    mv += abs(rDiff);
    return (root->val - 1) + lDiff +
           rDiff;  // this keeps track of how many coins are at each node
  }

 public:
  int distributeCoins(TreeNode *root) {
    mv = 0;
    r(root);
    return mv;
  }
};

/*
1 + 3 + 3 + 3 + 5 + 5 + 4 + 3 + 2 + 1 + 1
*/