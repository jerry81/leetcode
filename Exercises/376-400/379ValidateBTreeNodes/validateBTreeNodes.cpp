/*

1361. Validate Binary Tree Nodes
Medium
1.3K
354
Companies
You have n binary tree nodes numbered from 0 to n - 1 where node i has two
children leftChild[i] and rightChild[i], return true if and only if all the
given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the
right child.

Note that the nodes have no values and that we only use the node numbers in this
problem.



Example 1:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:


Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false


Constraints:

n == leftChild.length == rightChild.length
1 <= n <= 104
-1 <= leftChild[i], rightChild[i] <= n - 1
Accepted
50.7K
Submissions
127.6K
Acceptance Rate
39.8%

*/

#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int parent = -1;
};

class Solution {
  unordered_map<int, Node*> nodes;

 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    // two directional edge
    // only one root (no parent)
    int rootCount = n;
    for (int i = 1; i <= n; ++i) {
      nodes[i] = new Node();
    }
    int counter = 1;
    for (int i : leftChild) {
      // populate i's parent
      if (i >= 1) {
        if (nodes[i]->parent == -1) {
          rootCount--;
          nodes[i]->parent = counter;
        } else if (nodes[i]->parent != counter) {
          // 2 parents
          return false;
        } else if (nodes[counter]->parent == i) {
          // 2 direction
          return false;
        }
      }
      counter++;
    }
    for (int i : rightChild) {
      // populate i's parent
      if (i >= 1) {
        if (nodes[i]->parent == -1) {
          rootCount--;
          nodes[i]->parent = counter;
        } else if (nodes[i]->parent != counter) {
          // 2 parents
          return false;
        } else if (nodes[counter]->parent == i) {
          // 2 direction
          return false;
        }
      }
      counter++;
    }
    return rootCount == 1;
  }
};