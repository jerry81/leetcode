/*

106. Construct Binary Tree from Inorder and Postorder Traversal
Medium
5.9K
87
Companies
Given two integer arrays inorder and postorder where inorder is the inorder
traversal of a binary tree and postorder is the postorder traversal of the same
tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

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
  vector<int> ino;
  vector<int> poo;
  TreeNode* buildTreeR(int p1, int p2) {
    TreeNode* root;
    if (p2-p1 == 0) return nullptr;

    // special case - single item
    if (p2-p1 == 1) {
      root->val = poo[p2];
      return root;
    }

    int pivot = poo[p2];
    root->val = pivot;
    int pivotino;
    for (int i = p1; i <= p2; ++i) {
      if (ino[i] == pivot) {
        pivotino = i;
        break;
      }
    }
    root->left = buildTreeR(p1, pivotino-1);
    root->right = buildTreeR(pivotino+1, p2);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // using recursion
    ino = inorder;
    poo = postorder;
    // special case - no items
    return buildTreeR(0, inorder.size() - 1);

    // make root from postorder last item
    // split into next recursive iteration on remaining subarrays
  }
};