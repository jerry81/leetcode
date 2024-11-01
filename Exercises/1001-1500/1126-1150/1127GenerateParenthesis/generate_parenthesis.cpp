/*


22. Generate Parentheses
Medium
Topics
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


Constraints:

1 <= n <= 8
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2.1M
Submissions
2.7M
Acceptance Rate
75.8%

*/

#include <vector>
#include <string>

using namespace std;

class Solution {
vector<string> res;
string r(int remain, int open, string cur) {
  if (remain == 0 && open == 0) if (cur.size() >=2 && cur.back() == ')') res.push_back(cur);

  // if (open == 1 && remain == 0) if (cur.size() >=1) res.push_back(cur+")");

  // close open
  if (open > 0) {
    r(remain, open-1, cur+")");
  }
  if (remain > 0) {
    r(remain-1, open+1, cur+"(");
  }

}
public:
    vector<string> generateParenthesis(int n) {
      r(n, 0, "");
      return res;
    }
};