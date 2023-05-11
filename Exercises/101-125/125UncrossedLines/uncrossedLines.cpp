/*

1035. Uncrossed Lines
Medium
2.2K
30
Companies
You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.



Example 1:


Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
Example 2:

Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2


Constraints:

1 <= nums1.length, nums2.length <= 500
1 <= nums1[i], nums2[j] <= 2000
Accepted
84.5K
Submissions
140.9K
Acceptance Rate
60.0%

*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  vector<vector<int>> lookup;
  vector<int> v1;
  vector<int> v2;
  int s1, s2;
string get_hash(int idx1, int idx2) {
  return to_string(idx1) + "," + to_string(idx2);
}

int maxUncrossedLinesR(int idx1, int idx2) {
   vector<int> results;
  for (int i = idx1; i < s1; ++i) {
    int curi = v1[i];
    int matchj = -1;

    for (int j = idx2; j < s2; ++j) {
      int curj = v2[j];
      if (curj == curi) {
        matchj = j;
        break;
      }
    }
    if (matchj > -1) {
      results.push_back(1+maxUncrossedLinesR(i+1, matchj+1));
    }
    if (results.empty()) return 0;

    int mx = *max_element(results.begin(), results.end());
    return mx;
  }
}

public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      v1 = nums1;
      v2 = nums2;
      s1 = nums1.size();
      s2 = nums2.size();
      for (int i = 0; i < s1; i++) {
        vector<int> tmp;
        for (int j = 0; j < s2; ++j) {
          tmp.push_back(-1);
        }
        lookup.push_back(tmp);
      }
      if (nums1.empty() || nums2.empty()) return 0;

      return maxUncrossedLinesR(0,0);
    }
};

/*

working on the examples

Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
02, 5125
    2152
02, 125
    2
10
OR
11, 125
    2152
10, 5
    152

2  5  1  2  5
10 5  2  1  5  2
(0,2) -- go for the closest edge
(1,1)
(2,3)
(3,2) or (3,5)

feels like a recursive problem



Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2

1    3     7     1    7    5
1    9     2     5    1

*/



/*

on case 53 out of 70+, TLE

nums1 =
[1,5,3,5,3,5,5,4,4,3,2,3,5,4,5,4,5,2,5,3,3,1,4,4,3,1,1,1,4,4]
nums2 =
[1,3,2,2,5,2,3,1,1,3,5,4,5,5,3,5,4,1,2,5]


opportunities for memoization??


*/