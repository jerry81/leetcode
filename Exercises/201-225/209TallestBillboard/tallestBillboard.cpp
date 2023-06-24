/*

956. Tallest Billboard
Hard
1K
35
Companies
You are installing a billboard and want it to have the largest height. The
billboard will have two steel supports, one on each side. Each steel support
must be an equal height.

You are given a collection of rods that can be welded together. For example, if
you have rods of lengths 1, 2, and 3, you can weld them together to make a
support of length 6.

Return the largest possible height of your billboard installation. If you cannot
support the billboard, return 0.



Example 1:

Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same
sum = 6. Example 2:

Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same
sum = 10. Example 3:

Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.


Constraints:

1 <= rods.length <= 20
1 <= rods[i] <= 1000
sum(rods[i]) <= 5000
Accepted
19.8K
Submissions
46.8K
Acceptance Rate
42.2%

*/

#include <vector>

using namespace std;

class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    if (rods.size() < 2) return 0;

    int res = 0;
    vector<pair<int, int>> possibleSupports;

    possibleSupports.push_back({rods[0], {rods[1]}});
    possibleSupports.push_back({0, rods[0] + rods[1]});
    possibleSupports.push_back({0,0});
    possibleSupports.push_back({rods[0], 0});
    possibleSupports.push_back({rods[1],0});
    if (rods[0] == rods[1] && rods[0] > res) res = rods[0];
    for (int i = 2; i < rods.size(); ++i) {
      vector<pair<int,int>> nextSupports;
      for (auto [a,b]: possibleSupports) {
        nextSupports.push_back({a,b});
        if (a == b) {
          nextSupports.push_back({a+rods[i], a});
        } else {
          int newa = a+rods[i];
          if (newa == b && newa > res) res = newa;

          int newb = b+rods[i];
          if (newb == a && newb > res) res = newb;
          nextSupports.push_back({newa, b});
          nextSupports.push_back({a, newb});
        }
      }
      possibleSupports=nextSupports;
    }
    // for (auto [a,b]: possibleSupports) {
    //   if (a == b && a > res) res = a;
    // }
    return res;
  }
};

/*

example analysis
Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same
sum = 10.

- so... disjoint subsets the way to go?
[1] [1,2] ... [1,2,3,4,5]
[2] [2,3] ... [2,3,4,5,6]

base case -
[1,2] - 2 items, equal return 2,2
- not equal return 0

[1] return 0
[] return 0

larger case

[1,3,4]

[3,4] -> 3,4
7,0

[3,4] -> 0
1+3, 4 - > 4
3+1,4
3,4+1
7+1, 0
7, 0+1

3, 4+1 -> 0
3+4,1 -> 0  - res is useless
0 8
1 7
4 4
3 5

another player [8 1 3 4]
8 [1,3,4]

0 16
8 8
9 7
1 15
12 4
11 5
3 13

12 [8 1 3 4]

0 28 past half sum drop it
12 16
20 8
12+9 7
9 7+9
1+12 15
1 15+12
...

rod count small <= 20
try this brute force method

more cases possible:
- can choose to just not use an item also

*/