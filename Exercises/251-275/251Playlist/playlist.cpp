/*

920. Number of Music Playlists
Hard
947
99
Companies
Your music player contains n different songs. You want to listen to goal songs
(not necessarily different) during your trip. To avoid boredom, you will create
a playlist so that:

Every song is played at least once.
A song can only be played again only if k other songs have been played.
Given n, goal, and k, return the number of possible playlists that you can
create. Since the answer can be very large, return it modulo 109 + 7.



Example 1:

Input: n = 3, goal = 3, k = 1
Output: 6
Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3],
[2, 3, 1], [3, 1, 2], and [3, 2, 1]. Example 2:

Input: n = 2, goal = 3, k = 0
Output: 6
Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1],
[2, 2, 1], [2, 1, 2], and [1, 2, 2]. Example 3:

Input: n = 2, goal = 3, k = 1
Output: 2
Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].


Constraints:

0 <= k < n <= goal <= 100
Accepted
24.4K
Submissions
47.1K
Acceptance Rate
51.7%

*/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
  const int MOD = pow(10, 9) + 7;
  vector<vector<int>> dp;
  int r(int i, int j, int k, int n) {
    if (dp[i][j] >= 0) return dp[i][j];

    if (i < j) {
      dp[i][j] = 0;
      return 0;
    }

    int choices = n - j + 1;
    long long int prod = choices * r(i - 1, j - 1, k, n);
    prod %= MOD;

    int choices2 = j - k;
    long long int prod2 = choices2 * r(i - 1, j, k, n);
    prod2 %= MOD;
    dp[i][j] = prod + prod2;
    return dp[i][j];
  }

 public:
  int numMusicPlaylists(int n, int goal, int k) {
    dp.resize(goal, vector<int>(n, -1));
    dp[0][0] = 1;
    return r(goal, n, k, n);
  }
};

/*
        dp counting problem.  make state tree
        n=3,k=2
            [],goal=3,k=1
        [1->{1}],2 [2->{1}] [3->{1}]
      [2],1  [3],1

        n=2
        [],3,0

        [1]     [2]
      [1] [2] [1] [2]

        // state respresented as
        // goal, cachedItems
        // i,countdown...

      */

/*

official: was right about memoization but that's about it
dp epiphany:  2 params - i,j
  - i is len of playlist
  - j is # unique songs

the start case dp[goal][n]

base case dp[0][0] = 1
dp[i][j] where i < j = 0;

relations
1.  play a unique song
dp[i-1][j-1] * (n-j+1) <-- play a unique song * number of unique songs
// as we get towards base case, unique songs increases
2.  replay old song
dp[i-1][j] * (j-k) <-- j-k is number of songs we can replay
// only use it if j > k
*/