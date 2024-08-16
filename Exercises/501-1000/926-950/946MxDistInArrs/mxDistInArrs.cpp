/*
624. Maximum Distance in Arrays
Medium
Topics
Companies
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.



Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0


Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.
Accepted
125.6K
Submissions
283K
Acceptance Rate
44.4%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int> maxes;
        vector<int> mins;
        for (vector<int> v: arrays) {
          maxes.push_back(*max_element(v.begin(), v.end()));
          mins.push_back(*min_element(v.begin(), v.end()));
        }
        return *max_element(maxes.begin(),maxes.end()) - *min_element(mins.begin(),mins.end());
    }
};