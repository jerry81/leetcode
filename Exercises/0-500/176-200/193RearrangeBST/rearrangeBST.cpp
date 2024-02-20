/*

1569. Number of Ways to Reorder Array to Get Same BST
Hard
1.2K
146
Companies
Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.



Example 1:


Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
Example 2:


Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST:
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
Example 3:


Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= nums.length
All integers in nums are distinct.
Accepted
28.8K
Submissions
50.5K
Acceptance Rate
57.0%

*/

#include <vector>

using namespace std;

class Solution {
vector<vector<long long>> pascal;
long long mod = 1e9 + 7;

void makePascal(int sz) {
  for (int i = 0; i < sz; ++i) {
    vector<long long> nextRow;
    if (i == 0) {
      nextRow.push_back(1);
    } else {
      vector<long long> prevRow = pascal[i-1];
      nextRow.resize(i+1);
      nextRow[0] = 1;
      nextRow[i] = 1;
      for (int j = 1; j < i; ++j) {
        nextRow[j] = (prevRow[j-1] + prevRow[j]) % mod;
      }
    }
    pascal.push_back(nextRow);
  }
}

long long dfs(vector<int> nums) {
  if (nums.size() < 3) return 1;

  int root = nums[0];
  vector<int> left;
  vector<int> right;
  for (int i = 1; i < nums.size(); ++i) {
    int cur = nums[i];
    if (cur < root) { left.push_back(cur); }
    else { right.push_back(cur); }
  }
  long long leftRes = dfs(left) % mod;
  long long rightRes = dfs(right) % mod;
  long long combos = (leftRes * rightRes) % mod;
  long long npickk = pascal[nums.size()-1][left.size()];
  return (combos * npickk) % mod;
}

public:
    int numOfWays(vector<int>& nums) {
      makePascal(nums.size());

      return dfs(nums) - 1;
    }
};