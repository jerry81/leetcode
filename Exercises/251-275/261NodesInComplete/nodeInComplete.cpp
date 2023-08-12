/*

222. Count Complete Tree Nodes
Easy
7.9K
432
Companies
Given the root of a complete binary tree, return the number of the nodes in the
tree.

According to Wikipedia, every level, except possibly the last, is completely
filled in a complete binary tree, and all nodes in the last level are as far
left as possible. It can have between 1 and 2h nodes inclusive at the last level
h.

Design an algorithm that runs in less than O(n) time complexity.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1


Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
Accepted
578.9K
Submissions
936.6K
Acceptance Rate
61.8%

*/

#include <algorithm>
#include <string>
#include <cmath>

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
  int rh(TreeNode *root) {
    if (root == nullptr) return 0;

    return max(1+rh(root->left), 1+rh(root->right));
  }

  string maxPath(TreeNode *root) {
    if (root == nullptr) return "";
    int leftH = rh(root->left);
    int rightH = rh(root->right);
    if (leftH <= rightH && rightH > 0) {
      return "R" + maxPath(root->right);
    } else if (leftH > 0) {
      return "L" + maxPath(root->left);
    }

    return "C";
  }

  int sumStr(string s) {
    if (s.empty()) return 0;
    if (s.size()==1) return 1;
    s.pop_back();
    int sum = pow(2,s.size());
    for (int i = 0; i < s.size(); ++i) {
    }
    return sum;
  }

 public:
  int countNodes(TreeNode *root) {
    return sumStr(maxPath(root));
  }
};