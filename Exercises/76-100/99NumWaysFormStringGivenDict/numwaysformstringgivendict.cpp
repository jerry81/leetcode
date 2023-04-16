/*

1639. Number of Ways to Form a Target String Given a Dictionary
Hard
409
21
Companies
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
Repeat the process until you form the string target.
Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.



Example 1:

Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
Example 2:

Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")


Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 1000
All strings in words have the same length.
1 <= target.length <= 1000
words[i] and target contain only lowercase English letters.
Accepted
10.9K
Submissions
25.1K
Acceptance Rate
43.6%

*/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {

    }
};

/*

build a trie would take #chars time O(N) to build trie
build freq map
0a  1a  ... lena
0b  .
0c  .
.   .
.
.
0z  1z

counting possibilities
handling gaps

["acca","bbbb","caca"] -> 'aba' expect 6

a 1  a 1  a 0  a 2

b 1  b 1  b 1  b 1

c 1  c 0   - seems excessive

- we dont care about cs

let the target "drive" the ds

- handle a

1 1

- handle b
  1 1

- handle a

    0  2

*/