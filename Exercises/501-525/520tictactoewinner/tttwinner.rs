/*

1275. Find Winner on a Tic Tac Toe Game
Easy
Topics
Companies
Hint
Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

Players take turns placing characters into empty squares ' '.
The first player A always places 'X' characters, while the second player B always places 'O' characters.
'X' and 'O' characters are always placed into empty squares, never on filled ones.
The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.



Example 1:


Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
Example 2:


Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.
Example 3:


Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.


Constraints:

1 <= moves.length <= 9
moves[i].length == 2
0 <= rowi, coli <= 2
There are no repeated elements on moves.
moves follow the rules of tic tac toe.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
117.8K
Submissions
217.8K
Acceptance Rate
54.1%
*/

impl Solution {

  pub fn tictactoe(moves: Vec<Vec<i32>>) -> String {
      let moves_len = moves.len();
    let mut grid:Vec<Vec<String>> = vec![vec![" ".to_string(); 3]; 3];
    let mut a_to_move = true;
    let player_A = &String::from("A");
    let player_B = &String::from("B");

    for mv in moves {
      let mut player = player_A;
      if !a_to_move {
        player = player_B;
      }
      a_to_move = !a_to_move;
      grid[mv[0] as usize][mv[1] as usize] = player.to_string();
    }
    for pl in vec![player_A, player_B] {
      // rows
      for i in 0..=2 {
        if grid[i][0] == *pl && grid[i][1] == *pl && grid[i][2] == *pl {
            return pl.to_string();
        }
      }
      // rows
        for j in 0..=2 {
          if grid[0][j] == *pl && grid[1][j] == *pl && grid[2][j] == *pl {
              return pl.to_string();
          }
        }

      // 2 diagonals
      if grid[0][0] == *pl && grid[1][1] == *pl && grid[2][2] == *pl {
      return pl.to_string();
      }
      if grid[2][0] == *pl && grid[1][1] == *pl && grid[0][2] == *pl { return pl.to_string(); }


    }

        if moves_len < 9 {
            return "Pending".to_string();
        }

        "Draw".to_string()
  }
}