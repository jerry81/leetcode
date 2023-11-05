/*

1535. Find the Winner of an Array Game
Medium
631
33
Companies
Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0]
and arr[1]). In each round of the game, we compare arr[0] with arr[1], the
larger integer wins and remains at position 0, and the smaller integer moves to
the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.

It is guaranteed that there will be a winner of the game.



Example 1:

Input: arr = [2,1,3,5,4,6,7], k = 2
Output: 5
Explanation: Let's see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2
consecutive games. Example 2:

Input: arr = [3,2,1], k = 10
Output: 3
Explanation: 3 will win the first 10 rounds consecutively.


Constraints:

2 <= arr.length <= 105
1 <= arr[i] <= 106
arr contains distinct integers.
1 <= k <= 109
Accepted
31.6K
Submissions
64.6K
Acceptance Rate
48.8%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int a;
    int b;
    queue<int> q;
    for (int a : arr) {
      q.push(a);
    }
    int winCount = 0;
    bool init = false;
    bool aWon = false;
    a = q.front();
    q.pop();
    b = q.front();
    q.pop();
    while (winCount < k) {
      init = true;
      if (a > b) {
        if (init && aWon) winCount++;

        aWon = true;
        q.push(b);
        b = q.front();

      } else {
        if (init && !aWon) winCount++;

        aWon = false;
        q.push(a);
        a = q.front();
      }

      q.pop();
    }
    return aWon ? a : b;
  }
};