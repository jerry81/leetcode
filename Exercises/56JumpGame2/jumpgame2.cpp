/*

45. Jump Game II
Medium
10.8K
376
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000


*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
int jumpR(vector<int> nums, int idx) {
  if (idx >= (nums.size() - 1)) return 0;

  vector<int> choices;

  int jumpMax = nums[idx];

  if (jumpMax == 0) return 100000000;

  if ((jumpMax + idx) >= (nums.size() - 1)) return 1;

  for (int i = 1; (i <= jumpMax); ++i) {
    int choice = 1 + jumpR(nums, idx+i);
    choices.push_back(choice);
  }

  return *min_element(choices.begin(), choices.end());
}

public:
    int jump(vector<int>& nums) {
      for (int i:nums) {
      }
      return jumpR(nums,0);
    }
};

int main() {
  Solution s;
  vector<int> test1 = {2,3,1,1,4};
  cerr << "expect 2 " << s.jump(test1) << endl;
  vector<int> test2 = {2,3,0,1,4};
  cerr << "expect 2 " << s.jump(test2) << endl;
  vector<int> loadtest = {8,4,3,4,0,0,9,7,2,3,5,7,3,1,1,5,1,8,6,1,1,6,1,1,8,0,4};
  cerr << "expect something " << s.jump(loadtest) << endl;
  vector<int> loadtest2 = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
  cerr << "expect something " << s.jump(loadtest2) << endl;
  return 0;
}