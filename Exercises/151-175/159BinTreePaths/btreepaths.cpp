/*

257. Binary Tree Paths
Easy
5.7K
247
Companies
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.



Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]


Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
Accepted
619.8K
Submissions
1M
Acceptance Rate
61.7%

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
#include <string>
using namespace std;
class Solution {
vector<string> paths;
string toS(vector<int> inp) {
  bool first = true;
  string ret = "";
  for (int i:inp) {
    if (first) {
      ret+=to_string(i);
      first = false;
    } else {
      ret+="->";
      ret+=to_string(i);
    }
  }
}
void t(TreeNode* root, vector<int> curPath) {
  if (root == nullptr) paths.push_back(toS(curPath));
  curPath.push_back(root->val);
  t(root->left, curPath);
  t(root->right, curPath);
}
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<int> empty;
      t(root, empty);
      return paths;
    }
};