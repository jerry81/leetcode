/*
2096. Step-By-Step Directions From a Binary Tree Node to Another
Medium
Topics
Companies
Hint
You are given the root of a binary tree with n nodes. Each node is uniquely
assigned a value from 1 to n. You are also given an integer startValue
representing the value of the start node s, and a different integer destValue
representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate
step-by-step directions of such path as a string consisting of only the
uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.



Example 1:


Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
Example 2:


Input: root = [2,1], startValue = 2, destValue = 1
Output: "L"
Explanation: The shortest path is: 2 → 1.


Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
1 <= startValue, destValue <= n
startValue != destValue
Seen this question in a real interview before?
1/5
Yes
No
Accepted
106.3K
Submissions
214.1K
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

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct TNP {
  int left = -1;
  int right = -1;
  int parent = -1;
};

class Solution {
  unordered_map<int, TreeNode*> parent_map; // Use objects instead of pointers

  void process_tree(TreeNode *cur, TreeNode *from) {
    if (!cur) return;

    if (from != nullptr) parent_map[cur->val] = from;

    process_tree(cur->left, cur);
    process_tree(cur->right, cur);
  }

 public:
  string getDirections(TreeNode *root, int startValue, int destValue) {
    process_tree(root, nullptr);

    queue<pair<int, string>> q;
    unordered_set<int> visited;
    q.push({startValue, ""});
    visited.insert(startValue);

    while (!q.empty()) {
      auto [cur, path] = q.front();
      q.pop();
      if (cur == destValue) {
        return path;
      }

      TNP& curNode = graph[cur];
      int l = curNode.left;
      int r = curNode.right;
      int p = curNode.parent;

      if (l != -1 && visited.find(l) == visited.end()) {
        q.push({l, path + "L"});
        visited.insert(l);
      }
      if (r != -1 && visited.find(r) == visited.end()) {
        q.push({r, path + "R"});
        visited.insert(r);
      }
      if (p != -1 && visited.find(p) == visited.end()) {
        q.push({p, path + "U"});
        visited.insert(p);
      }
    }

    return "";
  }
};