/*

1578. Minimum Time to Make Rope Colorful
Medium
2.9K
89
Companies
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors
where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons
to be of the same color, so she asks Bob for help. Bob can remove some balloons
from the rope to make it colorful. You are given a 0-indexed integer array
neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove
the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.



Example 1:


Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
Example 2:


Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any
balloons from the rope. Example 3:


Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1
second to remove. There are no longer two consecutive balloons of the same
color. Total time = 1 + 1 = 2.


Constraints:

n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.
Accepted
156.2K
Submissions
248.1K
Acceptance Rate
63.0%

*/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  unordered_map<int, int> memo;
  int r(int idx, unordered_set<char> visited, int accum, string& colors,
        vector<int>& neededTime) {
    if (memo.find(idx) != memo.end()) return memo[idx];

    if (idx >= colors.size()) return visited.empty() ? accum : 0;

    char cur = colors[idx];

    if (visited.find(cur) == visited.end()) {
      // leave it
      memo[idx] = r(idx + 1, colors, neededTime, visited);
      return memo[idx];
    }

    // take it or leave it
    int res2 = memo[idx] = min(r(idx + 1, colors, neededTime, visited))
  }

 public:
  int minCost(string colors, vector<int>& neededTime) {
    unordered_set<char> visited;
    for (char c : colors) visited.insert(c);
  }
};