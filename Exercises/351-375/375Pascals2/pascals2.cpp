/*
119. Pascal's Triangle II
Easy
4.2K
313
Companies
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]


Constraints:

0 <= rowIndex <= 33


Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

Accepted
739.3K
Submissions
1.2M
Acceptance Rate
61.9%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur = {1};
        if (rowIndex == 0) return cur;

        cur.push_back(1);
        if (rowIndex == 1) return cur;

        for (int i = 2; i <= rowIndex; ++i) {
          vector<int> nxt = {1};
          for (int j = 0; j < cur.size()-1; ++j) {
            nxt.push_back(cur[j]+cur[j+1]);
          }
          nxt.push_back(1);
          cur = nxt;
        }
        return cur;

    }
};