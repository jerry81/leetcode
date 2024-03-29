/*

771. Jewels and Stones
Easy
4.8K
561
Companies
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".



Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0


Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
Accepted
922.9K
Submissions
1M
Acceptance Rate
88.3%

*/

#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
      set<char> lookup;
      for (char c: jewels) {
        lookup.insert(c);
      }
      int res = 0;
      for (char c: stones) {
        if (lookup.find(c) != lookup.end()) res++;
      }
      return res;
    }
};