/*

129. Sum Root to Leaf Numbers
Medium
5.6K
96
Companies
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.



Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.


Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
Accepted
544.3K
Submissions
914.3K
Acceptance Rate
59.5%

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

 struct dfsNode {
   vector<int> path;
   TreeNode* root;
   int asInt() {
     string asS;
     for (int i: path) {
       asS += (i + '0');
     }
     return stoi(asS);
   }
   void print() {
     cout << "printing node" << endl;
     for (int i: path) {
       cout << i << endl;
     }
   }
 };

class Solution {
  vector<dfsNode> getPaths(dfsNode rtN) {
    dfsNode rootN;
    rootN = rtN;
    TreeNode* root = rtN.root;
    vector<dfsNode> ret;
    if (root == nullptr) return ret;

    vector<int> newpath = rtN.path;
    newpath.push_back(root->val);
    rootN.path = newpath;

    if ((root->left == nullptr) && (root->right == nullptr)) {
      ret.push_back(rootN);
      return ret;
    }

    if (root->left != nullptr) {
      dfsNode leftN;
      leftN.path = newpath;
      leftN.root = root->left;
      vector<dfsNode> leftPaths = getPaths(leftN);
      ret.insert(ret.end(), leftPaths.begin(), leftPaths.end());
    }

    if (root->right != nullptr) { // DRY
      dfsNode rightN;
      rightN.path = newpath;
      rightN.root = root->right;
      vector<dfsNode> rightPaths = getPaths(rightN);
      ret.insert(ret.end(), rightPaths.begin(), rightPaths.end());
    }

    return ret;
  }
public:
    int sumNumbers(TreeNode* root) {
      dfsNode rootN;
      rootN.root = root;
      vector<dfsNode> paths = getPaths(rootN);
      int sum = 0;
      for (dfsNode d:paths) {
        sum+= d.asInt();
      }
      return sum;
    }
};