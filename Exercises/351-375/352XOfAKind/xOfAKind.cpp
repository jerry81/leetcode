/*

914. X of a Kind in a Deck of Cards
Easy
1.7K
461
Companies
You are given an integer array deck where deck[i] represents the number written on the ith card.

Partition the cards into one or more groups such that:

Each group has exactly x cards where x > 1, and
All the cards in one group have the same integer written on them.
Return true if such partition is possible, or false otherwise.



Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.


Constraints:

1 <= deck.length <= 104
0 <= deck[i] < 104
Accepted
111.5K
Submissions
367.2K
Acceptance Rate
30.4%

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
      unordered_map<int, int> freq;
      for (int i: deck) {
        freq[i]++;
      }

      int base = -1;

      for (auto [_,v]:freq) {
        if (v < 2) return false;
        if (base < 0) {
          base = v;
        }  else {
          if (base!=v) return false;
        }
      }
      return true;
    }
};