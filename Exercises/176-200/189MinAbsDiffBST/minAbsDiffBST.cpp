/*

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.



Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1

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
vector<int> items;
void r(TreeNode* root) {
  if (root==nullptr) return;

  items.push_back(root->val);
  r(root->left);
  r(root->right);
}

int getMinDist() {
  int ret = INT_MAX;
  if (items.size() <= 1) return 0;

  for (int i = 1; i < items.size(); ++i) {
    int diff = items[i] - items[0];
    if (diff < ret) {
      ret = diff;
    }
  }
  return ret;
}
public:
    int getMinimumDifference(TreeNode* root) {
      r(root);
      sort(items.begin(), items.end());
      return getMinDist();
    }
};