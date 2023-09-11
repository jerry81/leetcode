/*

783. Minimum Distance Between BST Nodes
Easy
3.3K
402
Companies
Given the root of a Binary Search Tree (BST), return the minimum difference
between the values of any two different nodes in the tree.



Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1


Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105


Note: This question is the same as 530:
https://leetcode.com/problems/minimum-absolute-difference-in-bst/

Accepted
228.1K
Submissions
383.5K
Acceptance Rate
59.5%

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

#include <climits>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  vector<int> flat;
  void r(TreeNode *root) {
    if (root==nullptr) return;

    r(root->left);
    flat.push_back(root->val);
    r(root->right);
  }

 public:
  int minDiffInBST(TreeNode *root) {
    // inorder traversal should be sequential
    r(root);
    for (int f : flat) {
      cout << "f is " << f << endl;
    }
  }
};