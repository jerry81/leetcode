/*


1678. Goal Parser Interpretation
Easy
Topics
Companies
Hint
You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.



Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"
Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"


Constraints:

1 <= command.length <= 100
command consists of "G", "()", and/or "(al)" in some order.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
235.5K
Submissions
270.6K
Acceptance Rate
87.1%

*/

impl Solution {
  pub fn interpret(command: String) -> String {
    let mut res: Vec<char> = Vec::new();
    let mut nxtCommand= command;
    while !nxtCommand.is_empty() {
      let mut nxtnxt:String = String::new();
      if nxtCommand.starts_with("G") {
        res.push('G');
        nxtnxt = nxtCommand.chars().skip(1).collect();
      } else if nxtCommand.starts_with("()") {
        res.push('o');
        nxtnxt = nxtCommand.chars().skip(2).collect();
      } else {
        res.push('a');
        res.push('l');
        nxtnxt = nxtCommand.chars().skip(4).collect();
      }
      nxtCommand = nxtnxt;
    }
    res.iter().collect()
  }
}