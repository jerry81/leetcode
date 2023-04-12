/*

71. Simplify Path
Medium
3.6K
708
Companies
Given a string path, which is an absolute path (starting with a slash '/') to a
file or directory in a Unix-style file system, convert it to the simplified
canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a
double period '..' refers to the directory up a level, and any multiple
consecutive slashes (i.e. '//') are treated as a single slash '/'. For this
problem, any other format of periods such as '...' are treated as file/directory
names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to
the target file or directory (i.e., no period '.' or double period '..') Return
the simplified canonical path.



Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root
level is the highest level you can go. Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by
a single one.


Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
Accepted
512.1K
Submissions
1.3M
Acceptance Rate
39.7%

*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
  vector<string> stk;
  vector<string> split(string str) {
    // Returns first token
    cout << "splitting"<<endl;
    vector<string> ret;
    char *token = strtok(str.data(), "/");
    cout << "tok is " << token << endl;

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != nullptr) {
      ret.push_back(token);
      token = strtok(nullptr, "/");

    }

    return ret;
  }

 public:
  string simplifyPath(string path) {
    // split by /
    // for each token
    // if '.' drop
    // if '..' pop if stk not empty
    // if empty drop
    // else add
    cout << "starting shit " << endl;
    vector<string> tokens = split(path);
    cout << "len is " << tokens.size() << endl;
    for (string s: tokens) {
      cout << "s is " << s << endl;
    }
    cout << "returning " << endl;
    return "";
  }
};