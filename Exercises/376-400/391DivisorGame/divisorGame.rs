/*

1025. Divisor Game
Easy
2K
4K
Companies
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.



Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.


Constraints:

1 <= n <= 1000
Accepted
226.4K
Submissions
332.4K
Acceptance Rate
68.1%

*/

impl Solution { // module Solution - equiv to class or struct
    pub fn divisor_game(n: i32) -> bool { // public, function, i32 - 32-bit signed integer returns bool
      // recursive min-max
      return r(n,true);
    }

    fn r(n: i32, bool alice) -> bool {
        if (n == 1) return !alice;

        bool ret = false;
        for i in 1..(n/2) {
          if (n%i == 0) {
            if (r(n/i, !alice)) ret = true;
          }
        }

        return ret;
    }
}