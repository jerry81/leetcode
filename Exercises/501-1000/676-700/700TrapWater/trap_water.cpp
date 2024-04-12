/*
42. Trapping Rain Water
Hard
Topics
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2M
Submissions
3.2M
Acceptance Rate
61.1%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      vector<int> ltr;
      int cur_max = -1;
      for (int i: height) {
        cur_max = max(i,cur_max);
        ltr.push_back(cur_max);
      }
      cur_max = -1;
      int sz = height.size();
      vector<int> rtl;
      for (int i = sz-1; i >=0; --i) {
        cur_max = max(cur_max, height[i]);
        rtl.push_back(cur_max);
      }
      reverse(rtl.begin(),rtl.end());
      int res = 0;
      for (int idx = 0; idx < sz; ++idx) {
        int curl = ltr[idx];
        int curr = rtl[idx];
        int bounds = min(curl,curr);
        res+=max(bounds-height[idx], 0);
      }
      return res;
    }
};