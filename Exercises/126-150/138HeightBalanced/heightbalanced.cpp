/*

110. Balanced Binary Tree
Easy
8.9K
502
Companies
Given a binary tree, determine if it is
height-balanced
.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
Accepted
1.1M
Submissions
2.2M
Acceptance Rate
49.3%

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

 #include <vector>
 using namespace std;

class Solution {
int mn = 5001;
int mx = -1;

int traverse(TreeNode* cur, int depth) {
  if (cur == nullptr) {
    if (mn > depth) mn = depth;
    if (mx < depth) mx = depth;
  }

  traverse(cur->left, depth+1);
  traverse(cur->right, depth+1);
}
public:
    bool isBalanced(TreeNode* root) {
      traverse(root, 0);
      return mx-mn <=1;
    }
};