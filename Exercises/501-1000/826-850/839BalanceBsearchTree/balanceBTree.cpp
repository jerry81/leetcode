/*

1382. Balance a Binary Search Tree
Medium
Topics
Companies
Hint
Given the root of a binary search tree, return a balanced binary search tree
with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node
never differs by more than 1.



Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also
correct. Example 2:


Input: root = [2,1,3]
Output: [2,1,3]


Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
166.6K
Submissions
202.7K
Acceptance Rate
82.2%

*/

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
  vector<int> items;
  TreeNode* res = nullptr;
  void r(TreeNode *root) {
    if (!root) return;

    items.push_back(root->val);
    r(root->left);
    r(root->right);
  }

  void build(TreeNode* cur, vector<int> remain) {
  }

 public:
  TreeNode *balanceBST(TreeNode *root) {
    // same technique as previously - extract the elements first
    r(root);
    sort(items.begin(),items.end());
    // recursively build new tree
    build(res, items);
    return res;
  }
};