/*

2251. Number of Flowers in Full Bloom
Hard
672
16
Companies
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti,
endi] means the ith flower will be in full bloom from starti to endi
(inclusive). You are also given a 0-indexed integer array people of size n,
where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of
flowers that are in full bloom when the ith person arrives.



Example 1:


Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom
and when the people arrive. For each person, we return the number of flowers in
full bloom during their arrival. Example 2:


Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom
and when the people arrive. For each person, we return the number of flowers in
full bloom during their arrival.


Constraints:

1 <= flowers.length <= 5 * 104
flowers[i].length == 2
1 <= starti <= endi <= 109
1 <= people.length <= 5 * 104
1 <= people[i] <= 109
Accepted
18.2K
Submissions
34.7K
Acceptance Rate
52.6%

*/

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& people) {
    map<int, int> diffs;
    vector<int> prefixSums;
    for (vector<int> v : flowers) {
      diffs[v[0]] = 1;
      diffs[v[1] + 1] = -1;
    }
    int cur = 0;
    vector<int> positions;
    for (auto [k, v] : diffs) {
      positions.push_back(k);
      cur += v;
      prefixSums.push_back(cur);
    }
    vector<int> res;

    for (int p : people) {
      int tgtidx = lower_bound(positions.begin(), positions.end(), p) - positions.begin();
      int topush = prefixSums[tgtidx];
      if (tgtidx <= 0) {
        if (prefixSums[tgtidx] != p) topush = 0;
      } else {
        if (positions[tgtidx] != p) topush = prefixSums[tgtidx-1];
      }

      res.push_back(topush);
    }

    return res;
  }
};