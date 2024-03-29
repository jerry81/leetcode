/*

958. Check Completeness of a Binary Tree
Medium
2.8K
36
Companies
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:


Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.


Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000
Accepted
148.2K
Submissions
271.7K
Acceptance Rate
54.5%

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

#include <vector>
#include <iostream>
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
 bool flattenTree(TreeNode* root) {
    bool flag = false;
    vector<TreeNode*> q;
    q.push_back(root);
    if (root == nullptr) return true;

    int parentCount = 1;
    while (parentCount > 0) {
      parentCount = 0;
      vector<TreeNode*> nq;
      for (TreeNode* c:q) {
        if (c == nullptr) {
          flag = true;
          nq.push_back(nullptr);
          nq.push_back(nullptr);
        } else {
          if (flag) return false;
          TreeNode* l = c->left;
          TreeNode* r = c->right;
          if (l != nullptr) parentCount++;

          if (r != nullptr) parentCount++;

          nq.push_back(l);

          nq.push_back(r);
        }
      }
      q = nq;
    }
    return true;
  }
public:
    bool isCompleteTree(TreeNode* root) {
      // reuse bfs from 2 days ago
      return flattenTree(root);
    }
};