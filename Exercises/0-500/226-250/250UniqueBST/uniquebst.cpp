/*

95. Unique Binary Search Trees II
Medium
6.2K
404
Companies
Given an integer n, return all the structurally unique BST's (binary search
trees), which has exactly n nodes of unique values from 1 to n. Return the
answer in any order.



Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 8
Accepted
363.6K
Submissions
683.5K
Acceptance Rate
53.2%

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

#include <map>
#include <string>
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
  string to_hash(int i, int j) { return to_string(i) + "," + to_string(j); }
  vector<TreeNode *> r(int start, int end,
                       map<string, vector<TreeNode *>> &dp) {
    vector<TreeNode *> res;
    string curHash = to_hash(start, end);
    if (dp.find(curHash) != dp.end()) return dp[curHash];

    if (start > end) {
      res.push_back(NULL);
      dp[curHash] = res;
      return res;
    }

    for (int i = start; i <= end; ++i) {
      vector<TreeNode *> leftTree = r(start, i - 1, dp);
      vector<TreeNode *> rightTree = r(i + 1, end, dp);

      for (TreeNode *l : leftTree) {
        for (TreeNode *r : rightTree) {
          TreeNode *tn = new TreeNode(i, l, r);
          res.push_back(tn);
        }
      }
      dp[curHash] = res;
    }

    return res;
  }

 public:
  vector<TreeNode *> generateTrees(int n) {
    int start = 1;
    int end = n;
    map<string, vector<TreeNode *>> dp;
    return r(1, n, dp);
  }
};

// make in one pass?
// low,high
// 1,4

/*
123
132
213
x 231
312
321

1,n,2,n,3
1,n,3,2,n
2,1,3,n,n
3,1,n,n,2
3,2,n,1,n

1234
1243
1324
1423
1432
2134
2143
x2314
x2341
x2413
x2431
x3124
3142
x3214
3241

1,n,2,n,3,n,4
1,n,2,n,4,3,n
1,n,3,2,4,n
1,n,4,2,n,n,3
1,n,4,3,n,2
2,1,3,n,n,n,4
2,1,4,n,n,3
3,1,4,n,2
3,2,4,1
4,1,n,n,2,n,3
4,1,n,n,3,2
4,2,n,1,3
4,3,n,1,n,n,2
4,3,n,2,n,1

1,n,x
2,1,x
3,x,4
4,x,n

1,n,x
2,1,x
3,[2,1],[4,5]
4,x,n
5,x,n

*/