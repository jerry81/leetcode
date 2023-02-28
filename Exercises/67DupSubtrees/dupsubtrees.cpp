/*

652. Find Duplicate Subtrees
Medium
4.3K
355
Companies
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.



Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]


Constraints:

The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200
Accepted
191.2K
Submissions
334.7K
Acceptance Rate
57.1%

*/

/**
 * Definition for a binary tree node.

 */

#include <vector>
#include <unordered_map>
#include <string>

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
unordered_map<int, vector<vector<int>>> paths;
void getPath(TreeNode* leaf, vector<int> path) {
  vector<int> tempPath = path;
  tempPath.push_back(leaf->val);
  paths[tempPath.size()].push_back(tempPath);
  if (leaf->left != nullptr) {
    getPath(leaf->left, tempPath);
  }

  if (leaf->right != nullptr) {
    getPath(leaf->right, tempPath);
  }
}

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      // recursively build the path to all leaves from both children
      vector<int> empty;
      if (root->left != nullptr) {
        getPath(root->left, empty);
      }
      if (root->right != nullptr) {
        getPath(root->right, empty);
      }


    }
};