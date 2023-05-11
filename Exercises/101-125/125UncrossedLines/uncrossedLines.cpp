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
using namespace std;

class Solution {

public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.empty() || nums2.empty()) return 0;
      int ret = 0;
      vector<int> results;
      for (int i = 0; i < nums1.size(); ++i) {
        int curi = nums1[i];
        int nextj = -1;
        for (int j = 0; j < nums2.size(); ++j) {
          int curj = nums2[j];
          if (curi == curj) {
            nextj = j;
            break;
          }
        }
        if (nextj >= 0) {
          std::vector<int>::iterator start = nums1.begin() + i;  // Start index (inclusive)
          std::vector<int>::iterator start2 = nums2.begin() + nextj;
          vector<int> sliced1(start, nums1.end());
          vector<int> sliced2(start2, nums2.end());

          results.push_back(1+maxUncrossedLines(sliced1, sliced2));
        }
      }
      if (results.empty()) return 0;
      int mx = *max_element(results.begin(), results.end());
      return mx;
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

