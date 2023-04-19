/*

1372. Longest ZigZag Path in a Binary Tree
Medium
1.6K
28
Companies
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node;
otherwise, move to the left child. Change the direction from right to left or
from left to right. Repeat the second and third steps until you can't move in
the tree. Zigzag length is defined as the number of nodes visited - 1. (A single
node has a length of 0).

Return the longest ZigZag path contained in that tree.



Example 1:


Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:


Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0


Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
Accepted
51.4K
Submissions
83.6K
Acceptance Rate
61.5%

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

#include <algorithm>
#include <string>
#include <vector>

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
  vector<string> paths;
  int max = 0;

  void dfs(TreeNode *root, string path, string prev, int curcount) {
    if (curcount > max) max = curcount;
    if (root->left == nullptr && root->right == nullptr) {
      paths.push_back(path);
    }
    if (root->left != nullptr) {
      string newpath = path + "L";
      int nextCount;
      if (prev == "") {
        nextCount = 1;
      } else if (prev == "R") {
        nextCount = 1 + curcount;
      } else {
        nextCount = 0;
      }
      dfs(root->left, newpath, "L", nextCount);
    }
    if (root->right != nullptr) {
      string newpath = path + "R";
      int nextCount;
      if (prev == "") {
        nextCount = 1;
      } else if (prev == "L") {
        nextCount = 1 + curcount;
      } else {
        nextCount = 0;
      }
      dfs(root->right, newpath, "R", nextCount);
    }
  }

 public:
  int longestZigZag(TreeNode *root) {
    dfs(root, "", "", 0);
    return max;
  }
};

/*
  get all paths to each leaf aka dfs
  RL
  RRR
  RRLRR
*/