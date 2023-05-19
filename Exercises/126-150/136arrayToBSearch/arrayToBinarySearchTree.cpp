/*

108. Convert Sorted Array to Binary Search Tree
Easy
9.5K
476
Companies
Given an integer array nums where the elements are sorted in ascending order,
convert it to a height-balanced binary search tree.



Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
Accepted
992.4K
Submissions
1.4M
Acceptance Rate
70.0%

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
 *
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;
class Solution {
  void buildR(vector<int>& nums, int low, int high, TreeNode* parent) {
    cout << "low." << low <<endl;
    cout << "high " << high << endl;
    if (high < low) return;
    if (high == low) {
      int val = nums[low];
      TreeNode* newN = new TreeNode(val);
      if (val > parent->val) {
        parent->right = newN;
      } else {
        parent->left = newN;
      }
      return;
    }

    int parentval = parent->val;

    int mid = (int)((high + low) / 2);

    int midv = nums[mid];
    TreeNode* nn = new TreeNode(midv);
    if (midv > parentval) {
      parent->right = nn;
    } else {
      parent->left = nn;
    }

    cout << "mid is " << mid << endl;

    buildR(nums, low, mid - 1, nn);
    buildR(nums, mid + 1, high, nn);
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int mid = (int)nums.size() / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    buildR(nums, 0, mid - 1, root);
    buildR(nums, mid + 1, nums.size() - 1, root);
    return root;
  }
};

/*

recursive
- keep pointer to root
- take mid

*/