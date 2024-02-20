/*

1282. Group the People Given the Group Size They Belong To
Medium
1.7K
553
Companies
There are n people that are split into some unknown number of groups. Each
person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of
the group that person i is in. For example, if groupSizes[1] = 3, then person 1
must be in a group of size 3.

Return a list of groups such that each person i is in a group of size
groupSizes[i].

Each person should appear in exactly one group, and every person must be in a
group. If there are multiple answers, return any of them. It is guaranteed that
there will be at least one valid solution for the given input.



Example 1:

Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
Explanation:
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] =
groupSizes[2] = 3. The third group is [3,4,6]. The size is 3, and groupSizes[3]
= groupSizes[4] = groupSizes[6] = 3. Other possible solutions are
[[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]]. Example 2:

Input: groupSizes = [2,1,3,3,3,2]
Output: [[1],[0,5],[2,3,4]]


Constraints:

groupSizes.length == n
1 <= n <= 500
1 <= groupSizes[i] <= n
Accepted
113.1K
Submissions
131.8K
Acceptance Rate
85.8%

*/

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    map<int, vector<int>> freqMaps;
    int n = groupSizes.size();
    for (int i = 0; i < n; ++i) {
      int item = groupSizes[i];
      if (freqMaps.find(item) == freqMaps.end()) freqMaps[item] = {};

      freqMaps[item].push_back(i);
    }
    vector<vector<int>> res;
    for (auto [k, v] : freqMaps) {
      vector<int> vtemp = v;
      vector<int> tmp;
      while (!vtemp.empty()) {
        if (tmp.size() == k) {
          res.push_back(tmp);
          tmp = {};
        }
        tmp.push_back(vtemp.back());
        vtemp.pop_back();
      }
      res.push_back(tmp);
    }

    return res;
  }
};