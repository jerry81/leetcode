/*

2660. Determine the Winner of a Bowling Game
Easy
Topics
Companies
Hint
You are given two 0-indexed integer arrays player1 and player2, representing the number of pins that player 1 and player 2 hit in a bowling game, respectively.

The bowling game consists of n turns, and the number of pins in each turn is exactly 10.

Assume a player hits xi pins in the ith turn. The value of the ith turn for the player is:

2xi if the player hits 10 pins in either (i - 1)th or (i - 2)th turn.
Otherwise, it is xi.
The score of the player is the sum of the values of their n turns.

Return

1 if the score of player 1 is more than the score of player 2,
2 if the score of player 2 is more than the score of player 1, and
0 in case of a draw.


Example 1:

Input: player1 = [5,10,3,2], player2 = [6,5,7,3]

Output: 1

Explanation:

The score of player 1 is 5 + 10 + 2*3 + 2*2 = 25.

The score of player 2 is 6 + 5 + 7 + 3 = 21.

Example 2:

Input: player1 = [3,5,7,6], player2 = [8,10,10,2]

Output: 2

Explanation:

The score of player 1 is 3 + 5 + 7 + 6 = 21.

The score of player 2 is 8 + 10 + 2*10 + 2*2 = 42.

Example 3:

Input: player1 = [2,3], player2 = [4,1]

Output: 0

Explanation:

The score of player1 is 2 + 3 = 5.

The score of player2 is 4 + 1 = 5.

Example 4:

Input: player1 = [1,1,1,10,10,10,10], player2 = [10,10,10,10,1,1,1]

Output: 2

Explanation:

The score of player1 is 1 + 1 + 1 + 10 + 2*10 + 2*10 + 2*10 = 73.

The score of player2 is 10 + 2*10 + 2*10 + 2*10 + 2*1 + 2*1 + 1 = 75.



Constraints:

n == player1.length == player2.length
1 <= n <= 1000
0 <= player1[i], player2[i] <= 10
Seen this question in a real interview before?
1/5
Yes
No
Accepted
34.7K
Submissions
101.8K
Acceptance Rate
34.1%

*/
impl Solution {
  pub fn is_winner(player1: Vec<i32>, player2: Vec<i32>) -> i32 {
      let mut p1score = 0;
      let mut p2score = 0;
      let upper = player1.len();

      p1score+=player1[0];
      p2score+=player2[0];

      for i in 1..upper {
        let mut framescore1 = player1[i];
        let secondCond = if i == 1 { false } else { player1[i-2] == 10 };
        if player1[i-1] == 10 || secondCond {
          framescore1 *= 2;
        }
        p1score+=framescore1;
        let mut framescore2 = player2[i];
        let secondCond2 = if i == 1 { false } else { player2[i-2] == 10 };
        if player2[i-1] == 10 || secondCond2 {
          framescore2 *= 2;
        }
        p2score+=framescore2;
      }
      if p1score > p2score {
          return 1
      } else if p2score > p1score {
          return 2
      } else {
          return 0
      }
      0
  }
}