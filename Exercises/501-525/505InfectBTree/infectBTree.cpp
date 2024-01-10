/*

2385. Amount of Time for Binary Tree to Be Infected
Medium
Topics
Companies
Hint
You are given the root of a binary tree with unique values, and an integer
start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.



Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
Example 2:


Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.


Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
41.8K
Submissions
70.4K
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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
  unordered_map<int, vector<int>> nodes;
  void build(TreeNode *root, int from) {
    if (!root) return;

    if (from >= 0) nodes[root->val].push_back(from);

    if (root->left) {
      nodes[root->val].push_back(root->left->val);
      build(root->left, root->val);
    }

    if (root->right) {
      nodes[root->val].push_back(root->right->val);
      build(root->right, root->val);
    }
  };

 public:
  int amountOfTime(TreeNode *root, int start) {
    // build neighbor map
    // do a bfs from start
    // count steps
    build(root, -1);
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);
    int res = -1;
    while (!q.empty()) {
      queue<int> nq;
      res++;
      while (!q.empty()) {
        int curi = q.front();
        q.pop();
        vector<int> neighbors = nodes[curi];
        for (int n: neighbors) {
          if (visited.find(n) != visited.end()) continue;

          visited.insert(n);
          nq.push(n);
        }
      }
      q = nq;
    }
    return res;
  }
};