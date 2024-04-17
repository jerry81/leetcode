/*

1974. Minimum Time to Type Word Using Special Typewriter
Easy
Topics
Companies
Hint
There is a special typewriter with lowercase English letters 'a' to 'z' arranged in a circle with a pointer. A character can only be typed if the pointer is pointing to that character. The pointer is initially pointing to the character 'a'.


Each second, you may perform one of the following operations:

Move the pointer one character counterclockwise or clockwise.
Type the character the pointer is currently on.
Given a string word, return the minimum number of seconds to type out the characters in word.



Example 1:

Input: word = "abc"
Output: 5
Explanation:
The characters are printed as follows:
- Type the character 'a' in 1 second since the pointer is initially on 'a'.
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer clockwise to 'c' in 1 second.
- Type the character 'c' in 1 second.
Example 2:

Input: word = "bza"
Output: 7
Explanation:
The characters are printed as follows:
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer counterclockwise to 'z' in 2 seconds.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'a' in 1 second.
- Type the character 'a' in 1 second.
Example 3:

Input: word = "zjpc"
Output: 34
Explanation:
The characters are printed as follows:
- Move the pointer counterclockwise to 'z' in 1 second.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'j' in 10 seconds.
- Type the character 'j' in 1 second.
- Move the pointer clockwise to 'p' in 6 seconds.
- Type the character 'p' in 1 second.
- Move the pointer counterclockwise to 'c' in 13 seconds.
- Type the character 'c' in 1 second.


Constraints:

1 <= word.length <= 100
word consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
41.5K
Submissions
55.4K
Acceptance Rate
74.9%

*/

impl Solution {
  pub fn min_time_to_type(word: String) -> i32 {
    let mut cur = 'a';
    let mut res = 0;
    for c in word.chars() {
      res += dist(cur, c);
      cur = c;
    }
    res
  }

  fn dist(a: char, b: char) -> i32 {
    let larger = a.max(b);
    let smaller = a.min(b);
    let diff1 = larger as u8 - smaller as u8;
    let di1 = diff1 as i32;
    let normalsmaller = smaller as u8 - 'a' as u8;
    let nsi1 = normalsmaller as i32;
    let normallarger = 'z' as u8 - larger as u8;
    let nsi2 = normallarger as i32;
    let diff2 = nsi1 + nsi2;
    diff1.min(diff2);
  }
}
