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
  TreeNode *res = nullptr;
  void r(TreeNode *root) {
    if (!root) return;

    items.push_back(root->val);
    r(root->left);
    r(root->right);
  }

  void build(TreeNode *parent, bool left,vector<int> remain) {
    if (parent) cout << "parent is " << parent->val << endl;

    cout << "remain " << endl;
    for (int i: remain) cout << i << endl;
    if (remain.empty()) return;


    int sz = remain.size();
    // mid idx
    int mididx = sz / 2;
    int nwval = remain[mididx];
    cout << "nwval is " << nwval << endl;
    TreeNode *cur = new TreeNode(nwval);


    if (parent == nullptr && res == nullptr) {
      cout << "settting res " << cur->val << endl;
      res = cur;
    } else {
      if (left) {
        parent->left = cur;
      } else {
        parent->right = cur;
      }
    }
    if (remain.size() == 1) return;
    // subseq left
    vector<int> l(remain.begin(), remain.begin() + mididx);
    build(cur, true, l);
    // subseq right
    vector<int> r(remain.begin() + mididx, remain.end());
    build(cur, false, r);
  }

 public:
  TreeNode *balanceBST(TreeNode *root) {
    // same technique as previously - extract the elements first
    r(root);
    sort(items.begin(), items.end());
    // recursively build new tree

    // test splitting
    // int half = items.size() / 2;
    // vector<int> left(items.begin(), items.begin() + half);
    // vector<int> right(items.begin() + half, items.end());
    build(nullptr, false, items);
    return res;
  }
};