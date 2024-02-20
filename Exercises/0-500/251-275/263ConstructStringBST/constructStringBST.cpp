/*

606. Construct String from Binary Tree
Easy
2.7K
3.2K
Companies
Given the root of a binary tree, construct a string consisting of parenthesis
and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping
relationship between the string and the original binary tree.



Example 1:


Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit
all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)" Example
2:


Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the
first parenthesis pair to break the one-to-one mapping relationship between the
input and the output.


Constraints:

The number of nodes in the tree is in the range [1, 104].
-1000 <= Node.val <= 1000
Accepted
224.3K
Submissions
347.9K
Acceptance Rate
64.5%

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

#include <string>

using namespace std;

class Solution {
 public:
  string tree2str(TreeNode *root) {
    string str = to_string(root->val);
    if (root->left != nullptr && root->right != nullptr) {
      str += "(";
      str += tree2str(root->left);
      str += ")";
      str += "(";
      str += tree2str(root->right);
      str += ")";
    } else if (root->left == nullptr && root->right != nullptr) {
      str += "()";
      str += "(";
      str += tree2str(root->right);
      str += ")";
    } else if (root->left != nullptr && root->right == nullptr) {
      str += "(";
      str += tree2str(root->left);
      str += ")";
    }
    return str;
  }
};