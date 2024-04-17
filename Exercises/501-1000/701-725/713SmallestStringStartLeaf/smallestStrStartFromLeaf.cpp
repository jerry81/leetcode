/*

988. Smallest String Starting From Leaf
Medium
Topics
Companies
You are given the root of a binary tree where each node has a value in the range
[0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree
and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.



Example 1:


Input: root = [0,1,2,3,4,3,4]
Output: "dba"
Example 2:


Input: root = [25,1,3,1,3,0,2]
Output: "adz"
Example 3:


Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"


Constraints:

The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25
Seen this question in a real interview before?
1/5
Yes
No
Accepted
84.2K
Submissions
160.8K
Acceptance Rate
52.3%

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
  // attempt 1: dfs traverse all paths
  // attempt 2: we need to identify leaves before updating res.
  // new param, isLeaf, must add a lookahead logic
  string res = "";
  void r(string accum, TreeNode *cur) {
    accum.push_back(cur->val + 'a');
    if (isLeaf(cur)) {
      reverse(accum.begin(), accum.end());
      if (res.empty() || res > accum) res = accum;
      return;
    }
    if (cur->left) r(accum, cur->left);
    if (cur->right) r(accum, cur->right);
  }

  bool isLeaf(TreeNode *n) { return !n->left && !n->right; }

 public:
  string smallestFromLeaf(TreeNode *root) {
    if (isLeaf(root)) {
        char c = root->val + 'a';
        string str(1, c); // review: string from char
        return str;
    }
    r("", root);
    return res;
  }
};