/*

652. Find Duplicate Subtrees
Medium
4.3K
355
Companies
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of
any one of them.

Two trees are duplicate if they have the same structure with the same node
values.



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

#include <iostream>
#include <string>
#include <unordered_map>
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
  struct DFSNode {
    vector<int> left;
    vector<int> right;
  };

  unordered_map<string, bool> paths;
  string hashPath(vector<int> left, vector<int> right, int root) {
    string ret = "";
    ret += "A: ";
    ret += "root";
    for (int i : left) {
      ret += "L";
      ret += to_string(i);
    }
    for (int i : right) {
      ret+= "R";
      ret+=to_string(i);
    }
    return ret;
  }
  vector<TreeNode *> results;

  DFSNode getPath(TreeNode *root) {
    DFSNode empty;
    if (root == nullptr) empty;

    DFSNode left = getPath(root->left);
    DFSNode right = getPath(root->right);
    left.left.push_back(root->val);
    right.right.push_back(root->val);
    if (root->left != nullptr) {
      left = getPath(leaf->left);
      left.push_back(leaf->val);
      return left;
    }

    // okay we need to consider both left and right trees.
    vector<int> right;
    if (leaf->right != nullptr) {
      right = getPath(leaf->right);
      right.push_back(leaf->val);
      return right;
    }

    string hash = hashPath(left, right, leaf->val);
    if (paths[hash]) {
      results.push_back(leaf);
    } else {
      paths[hash] = true;
    }

    empty.push_back(leaf->val);
    return empty;
  }

 public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    // recursively build the path to all leaves from both children
    vector<int> empty;
    if (root->left != nullptr) {
      getPath(root->left);
    }
    if (root->right != nullptr) {
      getPath(root->right);
    }

    return results;
    // but we need to return TreeNodes
  }
};