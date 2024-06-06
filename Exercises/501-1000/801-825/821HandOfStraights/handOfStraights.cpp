/*


846. Hand of Straights
Medium
Topics
Companies
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.



Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.



Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length


Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

Seen this question in a real interview before?
1/5
Yes
No
Accepted
215.4K
Submissions
384.5K
Acceptance Rate
56.0%

*/

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      // char counts
      map<int, int> ccounts;
      for (int i: hand) {
        if (ccounts.find(i) == ccounts.end()) {
          ccounts[i] = 1;
        } else {
          ccounts[i]++;
        }
      }
      while (!ccounts.empty()) {
        for (int i = 0; i < groupSize; ++i) {

        }
      }
    }
};