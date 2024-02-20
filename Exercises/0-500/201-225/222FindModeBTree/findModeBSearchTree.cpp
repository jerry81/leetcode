/*

501. Find Mode in Binary Search Tree
Easy
2.9K
661
Companies
Given the root of a binary search tree (BST) with duplicates, return all the
mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to
the node's key. The right subtree of a node contains only nodes with keys
greater than or equal to the node's key. Both the left and right subtrees must
also be binary search trees.


Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105


Follow up: Could you do that without using any extra space? (Assume that the
implicit stack space incurred due to recursion does not count). Accepted 194.6K
Submissions
391.9K
Acceptance Rate
49.7%

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

#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
  unordered_map<int, int> counts;
  void findModeR(TreeNode *root) {
    if (root == nullptr) return;

    counts[root->val]++;
    findModeR(root->left);
    findModeR(root->right);
  }

  static bool sortByFreq(pair<int,int> a, pair<int,int> b) {
   return a.second > b.second;
  }

 public:
  vector<int> findMode(TreeNode *root) {
    findModeR(root);
    vector<pair<int,int>> sorted;
    for (auto [val,count]: counts) {
      sorted.push_back({val,count});
    }
    sort(sorted.begin(), sorted.end(), sortByFreq);
    int freq = sorted[0].second;
    vector<int> res;
    res.push_back(sorted[0].first);
    for (int i = 1; i < sorted.size(); ++i) {
      if (freq == sorted[i].second) {
        res.push_back(sorted[i].first);
      } else {
        return res;
      }
    }
    return res;
  }
};

int main () {

}

// do a traversal
// count frequencies