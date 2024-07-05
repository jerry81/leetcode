/*

3200. Maximum Height of a Triangle
Easy
Topics
Companies
Hint
You are given two integers red and blue representing the count of red and blue colored balls. You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.

All the balls in a particular row should be the same color, and adjacent rows should have different colors.

Return the maximum height of the triangle that can be achieved.



Example 1:

Input: red = 2, blue = 4

Output: 3

Explanation:



The only possible arrangement is shown above.

Example 2:

Input: red = 2, blue = 1

Output: 2

Explanation:


The only possible arrangement is shown above.

Example 3:

Input: red = 1, blue = 1

Output: 1

Example 4:

Input: red = 10, blue = 1

Output: 2

Explanation:


The only possible arrangement is shown above.



Constraints:

1 <= red, blue <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
29K
Submissions
70.6K
Acceptance Rate
41.0%

*/

impl Solution {
  pub fn max_height_of_triangle(red: i32, blue: i32) -> i32 {
    // try start red and start blue
    let mut rc = red;
    let mut bc = blue;
    let mut ht1 = 0;
    let mut cursz = 1;
    let mut curred = true;
    loop {
      if curred {
        if rc < cursz {
          break
        } else {
          ht+=1;
          rc-=cursz;
        }
      } else {
        if bc < cursz {
          break
        } else {
          ht+=1;
          bc-=cursz;
        }
      }
      cursz+=1;
      curred = !curred;
    }
    rc = red;
    bc = blue;
    let mut ht2 = 0;
    cursz = 1;
    curred = false;
    loop {
      if curred {
        if rc < cursz {
          break
        } else {
          ht+=1;
          rc-=cursz;
        }
      } else {
        if bc < cursz {
          break
        } else {
          ht+=1;
          bc-=cursz;
        }
      }
      cursz+=1;
      curred = !curred;
    }
    ht1.max(ht2)
  }
}