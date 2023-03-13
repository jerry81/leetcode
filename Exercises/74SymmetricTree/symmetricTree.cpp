/*

101. Symmetric Tree
Easy
12.5K
283
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
Accepted
1.5M
Submissions
2.9M
Acceptance Rate
53.7%

*/

#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

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
  vector<int> flattenTree(TreeNode* root) {
    vector<int> ret;
    vector<TreeNode*> q;
    q.push_back(root);
    if (root == nullptr) return ret;

    int parentCount = 1;
    while (parentCount > 0) {
      parentCount = 0;
      vector<TreeNode*> nq;
      for (TreeNode* c:q) {
        if (c == nullptr) {
          ret.push_back(-101);
          nq.push_back(nullptr);
          nq.push_back(nullptr);
        } else {
          ret.push_back(c->val);
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
    return ret;
  }

 public:
  bool isSymmetric(TreeNode* root) {
    vector<int> flattened = flattenTree(root);
    int curLevel = 0;
    for (int i: flattened) {
      cout << i << endl;
    }
    while (true) {
      int rng = pow(2, curLevel);
      int bot = rng - 1;
      int top = bot + (rng - 1);
      if (top >= flattened.size()) break;

      for (int i = 0; i < (rng/2); ++i) {
        if (flattened[bot + i] != flattened[top - i]) return false;
      }
      ++curLevel;
    }
    return true;
  }
};