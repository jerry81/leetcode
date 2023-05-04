/*

649. Dota2 Senate
Medium
772
611
Companies
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".



Example 1:

Input: senate = "RD"
Output: "Radiant"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:

Input: senate = "RDD"
Output: "Dire"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And the third senator comes from Dire and he can ban the first senator's right in round 1.
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.


Constraints:

n == senate.length
1 <= n <= 104
senate[i] is either 'R' or 'D'.
Accepted
33K
Submissions
76.8K
Acceptance Rate
43.0%

*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
int p1 = -1;
int p2 = -1;
int tR = 0;
int tD = 0;
int banR = 0;
int banD = 0;


public:
    string predictPartyVictory(string senate) {
      for (int i = 0; i < senate.size(); ++i) {
        char c = senate[i];
        if (c == 'R') {
          if (banR > 0) {
            banR--;
          } else {
            tR++;
            banD++;
          }
        } else {
          if (banD > 0) {
            banD--;
          } else {
            tD++;
            banR++;
          }
        }
      }

      tR -= banR;
      tD -= banD;

      cout <<"banR is " << banR << endl;
            cout <<"banD is " << banD << endl;
                  cout <<"tD is " << tD << endl;
                        cout <<"tr is " << tR << endl;
                            return (tR > tD) ? "Radiant" : "Dire";
    }

};

/*

Strat - ban first available enemy
- 2 pointers - current ban R, current ban D - not needed
- 2 counters - Rbancount, DBanCount
- 2 counters - Rtotal, DTotal


strat 2 - after trying some examples
- there is a lot of lookahead
- should we do the indexing work up front?


*/