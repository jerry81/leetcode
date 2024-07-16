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
  unordered_map<int, TNP*> graph;
  void process_tree(TreeNode *cur, int from, bool left) {
    if (!cur) return;

    int cv = cur->val;
    TNP *new_node = new TNP();
    graph[cv] = new_node;
    if (from >= 0) {
      graph[cv]->parent = from;
      if (left) {
        graph[from]->left = cv;
      } else {
        graph[from]->right = cv;
      }
    }
    process_tree(cur->left, cv, true);
    process_tree(cur->right, cv, false);
  }

 public:
  string getDirections(TreeNode *root, int startValue, int destValue) {
    // populate graph then bfs
    process_tree(root, -1, false);

    // now bfs
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

      TNP* curNode = graph[cur];
      int l = curNode->left;
      int r = curNode->right;
      int p = curNode->parent;
      if (l >= 0 && visited.find(l) != visited.end()) {
        q.push({l, path+"L"});
      } else if (r >= 0 && visited.find(r) != visited.end()) {
        q.push({r, path+"R"});
      } else if (p >= 0 && visited.find(p) != visited.end()) {
        q.push({p, path+"U"});
      }
    }
    return "";
  }
};