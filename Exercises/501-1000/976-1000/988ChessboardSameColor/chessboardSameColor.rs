/*

3274. Check if Two Chessboard Squares Have the Same Color
Easy
Companies
Hint
You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.

Below is the chessboard for reference.



Return true if these two squares have the same color and false otherwise.

The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the number second (indicating its row).



Example 1:

Input: coordinate1 = "a1", coordinate2 = "c3"

Output: true

Explanation:

Both squares are black.

Example 2:

Input: coordinate1 = "a1", coordinate2 = "h3"

Output: false

Explanation:

Square "a1" is black and "h3" is white.



Constraints:

coordinate1.length == coordinate2.length == 2
'a' <= coordinate1[0], coordinate2[0] <= 'h'
'1' <= coordinate1[1], coordinate2[1] <= '8'
Seen this question in a real interview before?
1/5
Yes
No
Accepted
33.5K
Submissions
48.3K
Acceptance Rate
69.5%

*/

impl Solution {
  pub fn check_two_chessboards(coordinate1: String, coordinate2: String) -> bool {
      let (c11, c12) = (coordinate1.as_bytes()[0], coordinate1.as_bytes()[1]); // multiple decl, TIL: as_bytes
      let (c21, c22) = (coordinate2.as_bytes()[0], coordinate2.as_bytes()[1]);
      (c11 % 2 == c21 % 2) == (c12 % 2 == c22 % 2) // slick one-liner preserving logic
  }
}

/*
explain how (c11 % 2 == c21 % 2) == (c12 % 2 == c22 % 2) is equal to the nested if like i'm 5, and be louis ck
ChatGPT said:
ChatGPT
Alright, let’s break this down in a Louis C.K. style, but keep it clean, of course. So imagine you’ve got two kids, right? And you’re trying to figure out if they’re on the same kind of playground tile—you know, like the black or white tiles on a giant chessboard.
Now, let’s say each tile has a number. You don’t care what the number is, you just care if it’s odd or even. So you look at the numbers and say, “Hey, if both numbers are odd, they’re on the same color tile, right? And if both numbers are even, that’s also the same color. But if one’s odd and one’s even, they’re on different tiles.”
So, you’re sitting there, staring at these two numbers from each kid’s coordinates. And the first pair of numbers? You’re like, “Do these numbers have the same odd or even-ness?” If yes, then you check the second pair. And for the second pair, you’re like, “These match too, right?” If both pairs match, then guess what? Same tile color, easy-peasy!
Now, what I did here with the code, instead of doing all that if-this-and-then-that, is I just said, “Screw it, let’s just check if both pairs have the same odd or even-ness and be done with it.”
So if the first pair matches in their odd/even-ness and the second pair does too, we’re good. But if one pair matches and the other doesn’t, then it’s like, “Nah, they’re not on the same tile.”
This line (c11 % 2 == c21 % 2) == (c12 % 2 == c22 % 2) is like just saying, “Are these kids standing on the same kind of tile?” If both pairs agree, you get a true. If they don’t, you get a false. No need for all that if-this-then-that jazz.
It’s just simplifying things, like how you eventually just learn to keep the peace by not arguing with your kids when they tell you they know where they left their socks.
*/
