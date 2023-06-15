/*

1161. Maximum Level Sum of a Binary Tree
Medium
2.1K
73
Companies
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.



Example 1:


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
Example 2:

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2


Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
Accepted
138.1K
Submissions
208K
Acceptance Rate
66.4%

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

#include <queue>

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
public:
    int maxLevelSum(TreeNode* root) {
      int maxSum = 0;
      int maxRow = 1;
      int curRow = 1;
      queue<TreeNode*> nn;
      if (root!=nullptr) nn.push(root);

      int curSum = 0;
      while (!nn.empty()) {
        queue<TreeNode*> nextn;
        while (!nn.empty()) {
          TreeNode *cur = nn.front();
          nn.pop();
          curSum += cur->val;
        }
        if (curSum > maxSum) {
          maxSum = curSum;
          maxRow = curRow;
        }
        curRow++;
        nn = nextn;
      }
    }
};

// bfs to walk all items on each level