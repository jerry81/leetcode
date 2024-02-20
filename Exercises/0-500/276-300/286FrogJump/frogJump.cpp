/*

403. Frog Jump
Hard
4.2K
204
Companies
A frog is crossing a river. The river is divided into some number of units, and
at each unit, there may or may not exist a stone. The frog can jump on a stone,
but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order,
determine if the frog can cross the river by landing on the last stone.
Initially, the frog is on the first stone and assumes the first jump must be 1
unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k
+ 1 units. The frog can only jump in the forward direction.



Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd
stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3
units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the
5th and 6th stone is too large.


Constraints:

2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.
Accepted
193.9K
Submissions
446K
Acceptance Rate
43.5%

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<string, bool> dp;
  unordered_map<int, int> value_map;
  vector<int> possibilities = {-1, 0, 1};
  string toHash(int idx, int last) {
    return to_string(idx) + "," + to_string(last);
  }
  bool r(int idx, int last, vector<int>& stones, int& n) {
    string hsh = toHash(idx, last);
    if (dp.find(hsh) != dp.end()) return dp[hsh];

    if (idx >= n) return false;

    if (idx == n - 1) return true;

    int cur = stones[idx];

    if (idx == 0) {
      if (value_map.find(cur + 1) == value_map.end()) return false;

      dp[hsh] = r(value_map[cur + 1], 1, stones, n);
      return dp[hsh];
    }
    bool res = false;
    for (int p : possibilities) {
      int tryStone = last + p + cur;
      if (value_map.find(tryStone) == value_map.end()) continue;

      if (value_map[tryStone] > idx) {
        res = res || r(value_map[tryStone], last + p, stones, n);
      }
    }
    dp[hsh] = res;
    return res;
  }

 public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    for (int i = 0; i < n; ++i) {
      value_map[stones[i]] = i;
    }
    return r(0, 0, stones, n);
  }
};

/*

is it not typical dp?

*/