/*

1530. Number of Good Leaf Nodes Pairs
Medium
Topics
Companies
Hint
You are given the root of a binary tree and an integer distance. A pair of two
different leaf nodes of a binary tree is said to be good if the length of the
shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.



Example 1:


Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the
shortest path between them is 3. This is the only good pair. Example 2:


Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair
[4,6] is not good because the length of ther shortest path between them is 4.
Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].


Constraints:

The number of nodes in the tree is in the range [1, 210].
1 <= Node.val <= 100
1 <= distance <= 10
Seen this question in a real interview before?
1/5
Yes
No
Accepted
54.9K
Submissions
84.4K
Acceptance Rate
65.0%

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

bool customSort(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
class Solution {
  unordered_map<TreeNode *, vector<pair<TreeNode *, int>>>
      parents_dists;  // { child, map of {parent, distance} }

  unordered_map<TreeNode *, TreeNode *> parents;

  void push_parents_r(TreeNode *child, TreeNode *cur, int depth) {
    parents_dists[child].push_back({cur, depth});
    if (parents.find(cur) != parents.end())
      push_parents_r(child, parents[cur], depth + 1);
  }
  void r(TreeNode *cur, TreeNode *from) {
    if (cur == nullptr) return;

    if (from != nullptr) {
      parents[cur] = from;
      push_parents_r(cur, from, 1);
    }

    r(cur->left, cur);
    r(cur->right, cur);
  }

 public:
  int countPairs(TreeNode *root, int distance) {
    // dfs and gather info - get all leaves with their dist from root ?
    // no sometimes the path doesn't pass through root
    // so we need to walk all paths
    // could optimize with caching of dist from root
    r(root, nullptr);
    for (auto [k, v] : parents_dists) {
      cout << "looking at parent dists of " << k << endl;
      auto [p, dist] = v;
      cout << "parent is " << p.first << ", dist is " << dist << endl;
    }
    return 0;
  }
};