/*

1457. Pseudo-Palindromic Paths in a Binary Tree
Medium
Topics
Companies
Hint
Given a binary tree where node values are digits from 1 to 9. A path in the
binary tree is said to be pseudo-palindromic if at least one permutation of the
node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf
nodes.



Example 1:



Input: root = [2,3,1,3,1,null,1]
Output: 2
Explanation: The figure above represents the given binary tree. There are three
paths going from the root node to leaf nodes: the red path [2,3,3], the green
path [2,1,1], and the path [2,3,1]. Among these paths only red path and green
path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged
in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1]
(palindrome). Example 2:



Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1
Explanation: The figure above represents the given binary tree. There are three
paths going from the root node to leaf nodes: the green path [2,1,1], the path
[2,1,3,1], and the path [2,1]. Among these paths only the green path is
pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1


Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 9
Seen this question in a real interview before?
1/4
Yes
No
Accepted
126K
Submissions
186.6K
Acceptance Rate
67.5%

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

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  bool is_pp(const unordered_map<int, int> tested) {
    int odd_count = 0;
    for (const auto [_, v] : tested) {
      if (v % 2 == 1) {
        odd_count++;
        if (odd_count > 1) return false;
      }
    }
    return true;
  }

  int getPaths(unordered_map<int, int> &freq, TreeNode *cur) {
    if (!cur) {
      return 0;
    }

    bool traversed = false;
    freq[cur->val]++;
    int res = 0;
    if (cur->left) {
      res += getPaths(freq, cur->left);

      traversed = true;
    }

    if (cur->right) {
      res += getPaths(freq, cur->right);
      traversed = true;
    }

    if (!traversed) {
      if (is_pp(freq)) res = 1;
    }

    freq[cur->val]--; // popping from call stack, undo the changes.

    return res;
  }

 public:
  int pseudoPalindromicPaths(TreeNode *root) {
    unordered_map<int, int> empty;
    int res = getPaths(empty, root);
    return res;
  }
};

/*
  atttempt 1: mem limit exceeded
*/